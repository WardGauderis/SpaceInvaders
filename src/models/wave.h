//
// Created by ward on 12/9/19.
//

#ifndef SPACEINVADERS_WAVEMODEL_H
#define SPACEINVADERS_WAVEMODEL_H

#include "enemy.h"
#include "../utils/json.h"
#include "../utils/stopWatch.h"

namespace SI::model {

	class Wave : public Entity {
	public:
		Wave();

		explicit Wave(size_t waveNumber);

		void update() final;

		[[nodiscard]] const std::string& getTitle() const;

		[[nodiscard]] size_t getWaveNumber() const;

		[[nodiscard]] uint8_t getOpacity() const;

		~Wave() final = default;

	private:
		std::vector<std::weak_ptr<Enemy>> enemies;
		size_t waveNumber;
		std::string title;

		utils::Timer fadeInTimer;
		utils::Timer fadeOutTimer;
		uint8_t opacity;

		void parseWave();

		static std::vector<std::shared_ptr<Enemy>> parseRow(const nlohmann::json& row, float& y);

		static std::shared_ptr<Enemy> parseEnemy(const nlohmann::json& enemy);

		static void positionRow(const std::vector<std::shared_ptr<Enemy>>& row, float& y);
	};

}


#endif //SPACEINVADERS_WAVEMODEL_H
