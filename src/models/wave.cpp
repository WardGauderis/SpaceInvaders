//
// Created by ward on 12/9/19.
//
#include <fstream>

#include "wave.h"
#include "../utils/json.h"

SI::model::Wave::Wave() : Wave(0) {}

SI::model::Wave::Wave(const size_t waveNumber) {
	try {
		readFromFile(waveNumber);
	} catch (const std::exception& exception) {
		throw std::runtime_error(std::string(exception.what()) + " in wave " + std::to_string(waveNumber));
	}
}

void SI::model::Wave::update() {

}

void SI::model::Wave::readFromFile(const size_t waveNumber) {
	const std::string filename = "data/waves/wave" + std::to_string(waveNumber) + ".json";
	std::ifstream rFile(filename);

	bool waveExists = rFile.is_open();

	if (!waveExists) {
		deleteThis();
		return;
	}

	auto parser = nlohmann::json::parse(rFile);

	auto speed = parser["speed"].get<unsigned int>();
	auto wave = parser["wave"].get<std::vector<std::vector<std::string>>>();

	if (wave.size() > 5) throw std::runtime_error("Too many rows");

	for (size_t rowNumber = wave.size() - 1; rowNumber >= 0; --rowNumber) {
		try {
			const auto& row = wave[rowNumber];

			if (row.size() > 5) throw std::runtime_error("Too many enemies");

			for (size_t enemyNumber = 0; enemyNumber < row.size(); ++enemyNumber) {
				const auto& enemy = row[enemyNumber];

				try {
					enemies.emplace(enemyFactory(enemy));
				} catch (const std::exception& exception) {
					throw std::runtime_error(std::string(exception.what()) + " in enemy " + std::to_string(enemyNumber));
				}
			}
		} catch (const std::exception& exception) {
			throw std::runtime_error(std::string(exception.what()) + " in row " + std::to_string(rowNumber));
		}
	}

}

std::shared_ptr<SI::model::Enemy>
SI::model::Wave::enemyFactory(const std::string& enemyType) {
	if (enemyType == "default") {
		return std::make_shared<Enemy>();
	} else {
		throw std::runtime_error("Enemy type '" + enemyType + "' is not supported");
	}
}
