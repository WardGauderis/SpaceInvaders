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
		Wave();

		Wave(size_t waveNumber);

		void update() override;

		~Wave() override = default;

	private:
		std::unordered_set<std::shared_ptr<Enemy>> enemies;

		void readFromFile(size_t waveNumber);

		static std::shared_ptr<Enemy> enemyFactory(const std::string& enemyType);
	};

}


#endif //SPACEINVADERS_WAVEMODEL_H
