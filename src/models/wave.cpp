//
// Created by ward on 12/9/19.
//
#include <fstream>

#include "wave.h"
#include "../utils/json.h"

SI::model::Wave::Wave() : Wave(0) {}

SI::model::Wave::Wave(const size_t waveNumber) : waveNumber(waveNumber) {
	try {
		readFromFile();
	} catch (const std::exception& exception) {
		throw std::runtime_error("Failed to load 'wave" + std::to_string(waveNumber) + ".json': " + exception.what());
	}
}

void SI::model::Wave::update() {
	enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
	                             [](const std::weak_ptr<Enemy>& enemy) { return !enemy.lock(); }), enemies.end());
	if (enemies.empty()) *this = Wave(waveNumber + 1);
}

void SI::model::Wave::readFromFile() {
	const std::string filename = "data/waves/wave" + std::to_string(waveNumber) + ".json";
	std::ifstream rFile(filename);

	bool waveExists = rFile.is_open();

	if (!waveExists) {
		if (waveNumber == 0) throw std::runtime_error("at least one wave must be present");
		deleteThis();
		return;
	}

	auto parser = nlohmann::json::parse(rFile);

	auto speed = parser["speed"].get<unsigned int>();
	auto wave = parser["wave"].get<std::vector<std::vector<std::string>>>();

	float y = 3;
	for (const auto& row : wave) {
		std::vector<std::shared_ptr<Enemy>> rowEnemies;

		for (const auto& enemyType : row) {
			auto enemy = enemyFactory(enemyType);
			enemy->setVelocity({0.005f, -0.005f * speed});
			rowEnemies.emplace_back(enemy);
		}

		positionRow(rowEnemies, y);

		enemies.insert(enemies.end(), rowEnemies.begin(), rowEnemies.end());
		addModels(std::vector<std::shared_ptr<Entity>>(rowEnemies.begin(), rowEnemies.end()));
	}

}

std::shared_ptr<SI::model::Enemy>
SI::model::Wave::enemyFactory(const std::string& enemyType) {
	std::shared_ptr<Enemy> enemy;

	if (enemyType == "default") {
		enemy = std::make_shared<Enemy>();
	} else {
		throw std::runtime_error("Enemy type '" + enemyType + "' is not supported");
	}

	return enemy;
}

void SI::model::Wave::positionRow(const std::vector<std::shared_ptr<Enemy>>& row, float& y) {
	float fullWidth = 0;
	float maxHeight = 0;

	for (const auto& enemy: row) {
		fullWidth += enemy->getSize().x;
		maxHeight = std::max(maxHeight, enemy->getSize().y);
	}

	const float dy = 0.125;
	y += dy + maxHeight / 2;

	float remainingWidth = 8 - fullWidth;
	if (remainingWidth < 1)throw std::runtime_error("Not enough space for all enemies a row ");
	float dx = remainingWidth / (row.size() + 1.0f);

	float x = -4;
	for (const auto& enemy : row) {
		x += dx + enemy->getSize().x / 2;
		enemy->setPosition({x, y});
		x += enemy->getSize().x / 2;
	}

	y += maxHeight / 2;
}
