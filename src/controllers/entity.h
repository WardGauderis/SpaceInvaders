//
// Created by ward on 11/25/19.
//

#ifndef SPACEINVADERS_ENTITYCONTROLLER_H
#define SPACEINVADERS_ENTITYCONTROLLER_H

#include "../views/entity.h"

namespace SI::controller {
	/**
	 * abstract entity controller class
	 */
	class Entity {
	public:
		/**
		 * default constructor
		 */
		Entity();

		/**
		 * abstract function that is called every game tick
		 */
		virtual void update() = 0;

		/**
		 * check if this object may be deleted
		 * @return true if it may be deleted
		 */
		[[nodiscard]] bool mayDeleteThis() const;

		virtual ~Entity() = default;

	protected:
		/**
		 * indicate this object may be deleted
		 */
		void deleteThis();

	private:
		bool mustDelete;
	};

}

#endif //SPACEINVADERS_ENTITYCONTROLLER_H
