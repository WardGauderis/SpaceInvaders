//
// Created by ward on 12/24/19.
//

#ifndef SPACEINVADERS_WITCHMODEL_H
#define SPACEINVADERS_WITCHMODEL_H

#include "../enemy.h"

namespace SI::model {
	/**
	 * model class for the enemy witch who can reflect bullets
	 */
	class Witch : public Enemy {
	public:
		/**
		 * default constructor
		 */
		Witch();
		/**
		 * check for collision
		 * may reflect bullets
		 * @param entity entity
		 * @return true if it collides
		 */
		bool collidesWith(const std::shared_ptr<PhysicalEntity>& entity) final;

		~Witch() final = default;

	private:
		static std::uniform_int_distribution<int> distribution();

	};

}

#endif //SPACEINVADERS_WITCHMODEL_H
