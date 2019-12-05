//
// Created by ward on 11/25/19.
//

#ifndef SPACEINVADERS_ENTITYVIEW_H
#define SPACEINVADERS_ENTITYVIEW_H

#include "view.h"
#include "../models/entity.h"

namespace SI::view {

	class Entity : public View {
	public:
		Entity(const std::shared_ptr<sf::RenderWindow>& window, std::shared_ptr<model::Entity>  model);

	private:
		std::shared_ptr<model::Entity> model;
	};

}


#endif //SPACEINVADERS_ENTITYVIEW_H
