//
// Created by ward on 12/9/19.
//

#ifndef SPACEINVADERS_WAVECONTROLLER_H
#define SPACEINVADERS_WAVECONTROLLER_H

#include <unordered_set>
#include "enemy.h"

namespace SI::controller {

	class Wave : public Entity {
	public:
		Wave() = default;

		~Wave() override = default;

	private:
		std::unordered_set<std::shared_ptr<Enemy>> enemies;
	};

}

#endif //SPACEINVADERS_WAVECONTROLLER_H
