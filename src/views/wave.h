//
// Created by ward on 12/9/19.
//

#ifndef SPACEINVADERS_WAVE_H
#define SPACEINVADERS_WAVE_H

#include <unordered_set>
#include "enemy.h"

namespace SI::view {

	class Wave : public Entity {
	public:
		Wave(const std::shared_ptr<sf::RenderWindow>& window);

		~Wave() override = default;

	private:
		std::unordered_set<std::shared_ptr<Enemy>> enemies;
	};

}

#endif //SPACEINVADERS_WAVE_H
