//
// Created by ward on 12/15/19.
//
#include <functional>

#include "shield.h"
#include "explosion.h"
#include "enemy.h"

SI::model::Shield::ShieldSegment::ShieldSegment(const Type type) {
	std::function<bool(size_t, size_t)> requirement;
	switch (type) {
		case Type::full:
			requirement = []([[maybe_unused]] size_t x, [[maybe_unused]] size_t y) { return true; };
			break;
		case Type::rightBottom:
			requirement = [](size_t x, size_t y) { return y < x; };
			break;
		case Type::leftBottom:
			requirement = [](size_t x, size_t y) { return x + y + 1 < amount; };
			break;
		case Type::rightTop:
			requirement = [](size_t x, size_t y) { return amount < y + x + 1; };
			break;
		case Type::leftTop:
			requirement = [](size_t x, size_t y) { return x < y; };
			break;
	}
	for (size_t x = 0; x < points.size(); ++x) {
		for (size_t y = 0; y < points[x].size(); ++y) {
			if (!requirement(x, y)) continue;
			points[x][y] = true;
		}
	}
}

const utils::Vector& SI::model::Shield::ShieldSegment::size() {
	const static auto size = utils::Vector{0.25f, 0.25f};
	return size;
}

SI::model::Shield::Shield(const utils::Vector& position) : PhysicalEntity(0, {4 * ShieldSegment::size().x,
                                                                              3 * ShieldSegment::size().y}, position,
                                                                          {0, 0}, true) {
	ShieldSegment::Type type;
	for (size_t x = 0; x < segments.size(); ++x) {
		for (size_t y = 0; y < segments[x].size(); ++y) {

			if (x == 1 && y == 0) type = ShieldSegment::Type::leftTop;
			else if (x == 2 && y == 0) type = ShieldSegment::Type::rightTop;
			else if (x == 0 && y == 2) type = ShieldSegment::Type::rightBottom;
			else if (x == 3 && y == 2) type = ShieldSegment::Type::leftBottom;
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
	for (size_t x = 0; x < segments.size(); ++x) {
		for (size_t y = 0; y < segments[x].size(); ++y) {
			auto pos = convert(x, y, 0, 0);
			if (!AABB(pos, ShieldSegment::size(), entity->getPosition() - entity->getSize() / 2, entity->getSize()))
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
	for (size_t x1 = 0; x1 < segment.points.size(); ++x1) {
		for (size_t y1 = 0; y1 < segment.points[x1].size(); ++y1) {
			if (!segment.points[x1][y1]) continue;

			auto pos = convert(x0, y0, x1, y1);
			if (!entity->AABB(pos, ShieldSegment::size() / ShieldSegment::amount,
			                  entity->getPosition() - entity->getSize() / 2, entity->getSize()))
				continue;

			collides = true;
			onCollisionExplosion(x0, y0, x1, y1, entity);
		}
	}
	return collides;
}

void SI::model::Shield::onCollisionExplosion(int x0, int y0, int x1, int y1,
                                             const std::shared_ptr<PhysicalEntity>& entity) {
	int radius = 2;
	if (auto enemy = std::dynamic_pointer_cast<Enemy>(entity))
		radius += enemy->getValue();
	std::uniform_int_distribution<int> chance(0, 2);

	for (int x = -radius; x < radius; ++x) {
		for (int y = -radius; y < radius; ++y) {
			int X0 = x0;
			int Y0 = y0;
			int X1 = x1 + x;
			int Y1 = y1 + y;

			if (utils::Vector(static_cast<float>(x), static_cast<float>(y)).length() >=
			    static_cast<float>(radius))
				continue;
			if (chance(generator()) == 0) continue;
			if (!correct(X0, Y0, X1, Y1)) continue;

			segments.at(static_cast<size_t>(X0)).at(static_cast<size_t>(Y0)).points.at(static_cast<size_t>(X1)).at(
					static_cast<size_t>(Y1)) = false;
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

utils::Vector SI::model::Shield::convert(const int x0, const int y0, const int x1, const int y1) const {
	return position - size / 2 + ShieldSegment::size() * utils::Vector(static_cast<float>(x0), static_cast<float>(y0)) +
	       ShieldSegment::size() / ShieldSegment::amount *
	       utils::Vector(static_cast<float>(x1), static_cast<float>(y1));
}

bool SI::model::Shield::correct(int& x0, int& y0, int& x1, int& y1) {
	x0 += static_cast<int>(std::floor(static_cast<float>(x1) / ShieldSegment::amount));
	x1 = utils::positiveModulo(x1, ShieldSegment::amount);
	y0 += static_cast<int>(std::floor(static_cast<float>(y1) / ShieldSegment::amount));
	y1 = utils::positiveModulo(y1, ShieldSegment::amount);
	return x0 >= 0 && y0 >= 0 && x0 < 4 && y0 < 3;
}
