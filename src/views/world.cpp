//
// Created by ward on 12/3/19.
//

#include "world.h"
#include "../utils/transformation.h"

SI::view::World::World(const std::shared_ptr<model::World>& model): Entity(model) {
	utils::Transformation::get().setDimensions(800, 600);

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Space Invaders", sf::Style::Default, settings);
}

void SI::view::World::notify() {

}

void SI::view::World::update() {
	window->display();
}

void SI::view::World::addEntity(const std::shared_ptr<Entity>& entity) {
	entities.emplace(entity);
}

void SI::view::World::removeEntity(const std::shared_ptr<Entity>& entity) {
	entities.erase(entity);
}