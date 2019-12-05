//
// Created by ward on 11/25/19.
//

#include "entity.h"

#include <utility>

SI::view::Entity::Entity(const std::shared_ptr<sf::RenderWindow>& window, std::shared_ptr<model::Entity>  model)
		: View(window), model(std::move(model)) {}
