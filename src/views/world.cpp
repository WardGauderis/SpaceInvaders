//
// Created by ward on 12/3/19.
//

#include "world.h"
#include "../utils/transformation.h"

SI::view::World::World(std::shared_ptr<model::World> model) : Entity(), model(std::move(model)) {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	window = std::make_shared<sf::RenderWindow>(
			sf::VideoMode(utils::Transformation::get().getWidth(), utils::Transformation::get().getHeight()),
			"Space Invaders", sf::Style::Close, settings);
}

void SI::view::World::notify() {

}

void SI::view::World::update() {
	window->clear();
	for (const auto& entity: entities) {
		entity->update();
	}
	window->display();
}

void SI::view::World::addEntity(const std::shared_ptr<Entity>& entity) {
	entities.emplace(entity);
}

void SI::view::World::removeEntity(const std::shared_ptr<Entity>& entity) {
	entities.erase(entity);
}

std::shared_ptr<sf::RenderWindow> SI::view::World::getWindow() const {
	return window;
}
