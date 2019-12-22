//
// Created by ward on 12/15/19.
//
#include <functional>

#include "shield.h"
#include "explosion.h"
#include "bullet.h"
#include "enemy.h"

const utils::Vector SI::model::Shield::ShieldSegment::size = {0.25f, 0.25f};

SI::model::Shield::ShieldSegment::ShieldSegment(const Type type) {
	std::function<bool(int, int)> requirement;
	switch (type) {
		case Type::full:
			requirement = [](int x, int y) { return true; };
			break;
		case Type::rightbottom:
			requirement = [](int x, int y) { return y < x; };
			break;
		case Type::leftbottom:
			requirement = [](int x, int y) { return x < amount - 1 - y; };
			break;
		case Type::righttop:
			requirement = [](int x, int y) { return amount - 1 - x < y; };
			break;
		case Type::lefttop:
			requirement = [](int x, int y) { return x < y; };
			break;
	}
	for (size_t x = 0; x < points.size(); ++x) {
		for (size_t y = 0; y < points[x].size(); ++y) {
			if (!requirement(x, y)) continue;
			points[x][y] = true;
		}
	}
}

SI::model::Shield::Shield(const utils::Vector& position) : PhysicalEntity(0, {4 * ShieldSegment::size.x,
                                                                              3 * ShieldSegment::size.y}, position,
                                                                          {0, 0}, true) {
	ShieldSegment::Type type;
	for (size_t x = 0; x < segments.size(); ++x) {
		for (size_t y = 0; y < segments[x].size(); ++y) {

			if (x == 1 && y == 0) type = ShieldSegment::Type::lefttop;
			else if (x == 2 && y == 0) type = ShieldSegment::Type::righttop;
			else if (x == 0 && y == 2) type = ShieldSegment::Type::rightbottom;
			else if (x == 3 && y == 2) type = ShieldSegment::Type::leftbottom;
			else type = ShieldSegment::Type::full;

			segments[x][y] = ShieldSegment(type);
		}
	}
}

const std::array<std::array<SI::model::Shield::ShieldSegment, 3>, 4>& SI::model::Shield::getSegments() const {
	return segments;
}

bool SI::model::Shield::collidesWith(const std::shared_ptr<PhysicalEntity>& entity) {
	if (!AABB(position - size / 2, size, entity->getPosition() - entity->getSize() / 2, entity->getSize()))
		return false;

	bool collides = false;
	for (int x = 0; x < segments.size(); ++x) {
		for (int y = 0; y < segments[x].size(); ++y) {
			auto pos = convert(x, y, 0, 0);
			if (!AABB(pos, ShieldSegment::size, entity->getPosition() - entity->getSize() / 2, entity->getSize()))
				continue;

			collides |= collidesWithSegment(x, y, entity);
		}
	}
	return collides;
}

bool SI::model::Shield::collidesWithSegment(const int x0, const int y0,
                                            const std::shared_ptr<PhysicalEntity>& entity) {
	auto& segment = segments[x0][y0];
	bool collides = false;
	for (int x1 = 0; x1 < segment.points.size(); ++x1) {
		for (int y1 = 0; y1 < segment.points[x1].size(); ++y1) {
			if (!segment.points[x1][y1]) continue;

			auto pos = convert(x0, y0, x1, y1);
			if (!entity->AABB(pos, ShieldSegment::size / ShieldSegment::amount,
			                  entity->getPosition() - entity->getSize() / 2, entity->getSize()))
				continue;

			collides = true;
			onCollision(x0, y0, x1, y1, entity);
		}
	}
	return collides;
}

void SI::model::Shield::onCollision(const int x0, const int y0, const int x1, const int y1,
                                    const std::shared_ptr<PhysicalEntity>& entity) {
	int radius = 1;
	if (auto enemy = std::dynamic_pointer_cast<Enemy>(entity))
		radius += enemy->getLives() * 3;
	std::uniform_int_distribution<int> chance(0, 3);

	for (int x = -radius; x < radius; ++x) {
		for (int y = -radius; y < radius; ++y) {
			int X0 = x0;
			int Y0 = y0;
			int X1 = x1 + x;
			int Y1 = y1 + y;
			if(chance(generator) == 0) continue;
			if (!correct(X0, Y0, X1, Y1)) continue;
			segments.at(X0).at(Y0).points.at(X1).at(Y1) = false;
		}
	}

	const auto backupSize = size;
	const auto backupPosition = position;
	position = convert(x0, y0, x1, y1);
	size = entity->getSize() / 2;
	addModel(std::make_shared<Explosion>(*this));
	position = backupPosition;
	size = backupSize;
}

utils::Vector SI::model::Shield::convert(const size_t x0, const size_t y0, const size_t x1, const size_t y1) const {
	return position - size / 2 + ShieldSegment::size * utils::Vector(x0, y0) +
	       ShieldSegment::size / ShieldSegment::amount * utils::Vector(x1, y1);
}

bool SI::model::Shield::correct(int& x0, int& y0, int& x1, int& y1) {
	x0 += static_cast<int>(std::floor(static_cast<float>(x1) / ShieldSegment::amount));
	x1 = utils::positiveModulo(x1, ShieldSegment::amount);
	y0 += static_cast<int>(std::floor(static_cast<float>(y1) / ShieldSegment::amount));
	y1 = utils::positiveModulo(y1, ShieldSegment::amount);
	return x0 >= 0 && y0 >= 0 && x0 < 4 && y0 < 3;
}
