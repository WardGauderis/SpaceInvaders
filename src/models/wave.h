//
// Created by ward on 12/9/19.
//

#ifndef SPACEINVADERS_WAVEMODEL_H
#define SPACEINVADERS_WAVEMODEL_H

#include "../utils/json.h"
#include "../utils/stopWatch.h"
#include "enemy.h"

namespace SI::model {
/**
 * model class that handles the waves
 */
class Wave : public Entity
{
public:
        /**
         * construct wave 0 by reading wave0.json
         */
        Wave();

        /**
         * construct wave X by reading waveX.json
         * @param waveNumber X
         */
        explicit Wave(size_t waveNumber);

        /**
         * function that is called when the model is updated every tick
         * update timers and check if the next wave may start
         */
        void update() final;

        /**
         * get the wave title
         * @return title
         */
        [[nodiscard]] const std::string& getTitle() const;

        /**
         * get the wave number
         * @return number
         */
        [[nodiscard]] size_t getWaveNumber() const;

        /**
         * get the opacity of the title
         * @return opacity
         */
        [[nodiscard]] uint8_t getOpacity() const;

        ~Wave() final = default;

private:
        std::vector<std::weak_ptr<Enemy>> enemies;
        size_t waveNumber;
        std::string title;

        utils::Timer fadeInTimer;
        utils::Timer fadeOutTimer;
        uint8_t opacity;

        /**
         * parse the wave from a json file
         */
        void parseWave();

        /**
         * parse a row of enemies and position it
         * @param row json object
         * @param y position
         * @return enemies
         */
        static std::vector<std::shared_ptr<Enemy>> parseRow(const nlohmann::json& row, float& y);

        /**
         * parse an enemy (factory method)
         * @param enemy json object
         * @return enemy
         */
        static std::shared_ptr<Enemy> parseEnemy(const nlohmann::json& enemy);

        /**
         * position the enemies in a row
         * @param row enemies
         * @param y position
         */
        static void positionRow(const std::vector<std::shared_ptr<Enemy>>& row, float& y);
};

} // namespace SI::model

#endif // SPACEINVADERS_WAVEMODEL_H
