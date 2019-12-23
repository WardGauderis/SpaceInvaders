//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_WORLDVIEW_H
#define SPACEINVADERS_WORLDVIEW_H

#include <SFML/Audio.hpp>

#include "entity.h"
#include "../models/world.h"

namespace SI::view {
	/**
	 * view class for the world
	 */
	class World : public Entity {
	public:
		/**
		 * construct with the correct model, SFML window is created
		 * @param model pointer
		 */
		explicit World(std::shared_ptr<model::World> model);

		/**
		 * reset the world view
		 */
		void reset();

		/**
		 * notify the view for changes in the model
		 */
		void notify() final;

		/**
		 * function that is ran when the view is updated
		 */
		void update() final;

		/**
		 * add a new view to the world
		 * @param entity new view
		 */
		void addEntity(const std::shared_ptr<Entity>& entity);

		/**
		 * remove all views that may be deleted
		 */
		void removeEntities();

		/**
		 * get the world window
		 * @return SFML window
		 */
		std::shared_ptr<sf::RenderWindow> getWindow() const;

		~World() final = default;

	private:
		const std::shared_ptr<model::World> model;
		std::set<std::shared_ptr<Entity>, std::function<bool(const std::shared_ptr<SI::view::Entity>&,
		                                                     const std::shared_ptr<SI::view::Entity>&)>> entities;

		sf::RectangleShape dim;
		sf::Text instruction;
		sf::Text head;
	};

}

#endif //SPACEINVADERS_WORLDVIEW_H
