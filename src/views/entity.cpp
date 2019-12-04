//
// Created by ward on 11/25/19.
//

#include "entity.h"

SI::view::Entity::Entity(const std::shared_ptr<sf::RenderWindow>& window, const std::shared_ptr<model::Model>& model)
		: View(window, model) {}
