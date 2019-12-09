//
// Created by ward on 12/9/19.
//

#ifndef SPACEINVADERS_WAVEMODEL_H
#define SPACEINVADERS_WAVEMODEL_H

#include <unordered_set>
#include "enemy.h"

namespace SI::model {

	class Wave : public Entity {
	public:
		void update() override;

		~Wave() override = default;

	private:
		std::unordered_set<std::shared_ptr<Enemy>> enemies;
		static unsigned int number;
	};

}


#endif //SPACEINVADERS_WAVEMODEL_H
