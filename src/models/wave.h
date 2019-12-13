//
// Created by ward on 12/9/19.
//

#ifndef SPACEINVADERS_WAVEMODEL_H
#define SPACEINVADERS_WAVEMODEL_H

#include "enemy.h"

namespace SI::model {

	class Wave : public Entity {
	public:
		Wave();

		Wave(size_t waveNumber);

		void update() final;

		~Wave() final = default;

	private:
		std::vector<std::weak_ptr<Enemy>> enemies;
		size_t waveNumber;

		void readFromFile();

		static std::shared_ptr<Enemy> enemyFactory(const std::string& enemyType);

		static void positionRow(const std::vector<std::shared_ptr<Enemy>>& row, float& y);
	};

}


#endif //SPACEINVADERS_WAVEMODEL_H
