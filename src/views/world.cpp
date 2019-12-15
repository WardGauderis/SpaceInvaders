//
// Created by ward on 12/3/19.
//

#include <functional>

#include "world.h"
#include "../utils/transformation.h"

std::function<bool(const std::shared_ptr<SI::view::Entity>&,
                   const std::shared_ptr<SI::view::Entity>&)> cmpEntities = [](
		const std::shared_ptr<SI::view::Entity>& entity0, const std::shared_ptr<SI::view::Entity>& entity1) {
	if (entity0->drawOrder() == entity1->drawOrder()) return entity0 < entity1;
	else return entity0->drawOrder() < entity1->drawOrder();
};

SI::view::World::World(std::shared_ptr<model::World> model) : Entity(), model(std::move(model)), entities(cmpEntities) {
	if (!music.openFromFile("data/audio/The_Cannery.wav"))
		throw std::runtime_error("The_Cannery.wav must be present in data/audio");
	music.setLoop(true);
	music.play();

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	window = std::make_shared<sf::RenderWindow>(
			sf::VideoMode(utils::Transformation::get().getWidth(), utils::Transformation::get().getHeight()),
			"Space Invaders", sf::Style::Close, settings);
}

void SI::view::World::notify() {

}

void SI::view::World::update() {
	window->clear(sf::Color(30, 27, 25));

	for (const auto& entity: entities) {
		entity->update();
	}

	window->display();
}

void SI::view::World::addEntity(const std::shared_ptr<Entity>& entity) {
	entities.emplace(entity);
}

void SI::view::World::removeEntities() {
	for (auto it = entities.begin(); it != entities.end();) {
		if ((*it)->mayDeleteThis()) it = entities.erase(it);
		else ++it;
	}
}

std::shared_ptr<sf::RenderWindow> SI::view::World::getWindow() const {
	return window;
}
