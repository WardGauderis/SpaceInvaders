//
// Created by ward on 12/9/19.
//
#include <fstream>
#include <iostream>

#include "wave.h"

SI::model::Wave::Wave() : Wave(0) {}

SI::model::Wave::Wave(const size_t waveNumber) : waveNumber(waveNumber), fadeInTimer(60), fadeOutTimer(300),
                                                 opacity(0) {
	fadeInTimer.reset();
	fadeInTimer.start();
	fadeOutTimer.reset();
	fadeOutTimer.stop();
	try {
		parseWave();
	} catch (const std::exception& exception) {
		throw std::runtime_error("Failed to load 'wave" + std::to_string(waveNumber) + ".json': " + exception.what());
	}
}

void SI::model::Wave::update() {
	fadeInTimer.update();
	fadeOutTimer.update();

	if (fadeInTimer.ready()) {
		fadeInTimer.stop();
		fadeOutTimer.start();
		fadeInTimer.setTime(0);
		++opacity;
		if (opacity == 255) fadeInTimer.reset();
	}
	if (fadeOutTimer.ready()) {
		fadeOutTimer.stop();
		fadeOutTimer.setTime(0);
		--opacity;
		if (opacity == 0) fadeOutTimer.reset();
	}

	enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
	                             [](const std::weak_ptr<Enemy>& enemy) { return !enemy.lock(); }), enemies.end());

	if (enemies.empty()) {
		Wave newWave(waveNumber + 1);
		newWave.setObservers(getObservers());
		*this = newWave;
		notifyObservers();
	}
}

const std::string& SI::model::Wave::getTitle() const {
	return title;
}

size_t SI::model::Wave::getWaveNumber() const {
	return waveNumber;
}

void SI::model::Wave::parseWave() {
	const std::string filename = "data/waves/wave" + std::to_string(waveNumber) + ".json";
	std::ifstream rFile(filename);

	if (!rFile.is_open()) {
		if (waveNumber == 0) throw std::runtime_error("at least wave0.json must be present in data/waves");
		deleteThis();
		return;
	}

	auto wave = nlohmann::json::parse(rFile);

	title = wave.value<std::string>("title", "wave" + std::to_string(waveNumber));

	auto speed = wave.value<float>("speed", 1);
	if (speed < 0) throw std::runtime_error("wave speed must be positive");

	float y = 3;
	std::vector<std::shared_ptr<Enemy>> newEnemies;
	for (const auto& row: wave.at("rows")) {
		auto rowEnemies = parseRow(row, y);
		newEnemies.insert(newEnemies.end(), rowEnemies.begin(), rowEnemies.end());
	}

	for (const auto& enemy: newEnemies) {
		enemy->setVelocity({enemy->getVelocity().x, -0.002f * speed});
	}

	enemies.insert(enemies.end(), newEnemies.begin(), newEnemies.end());
	addModels(std::vector<std::shared_ptr<Entity>>(newEnemies.begin(), newEnemies.end()));
}

std::vector<std::shared_ptr<SI::model::Enemy>> SI::model::Wave::parseRow(const nlohmann::json& row, float& y) {
	auto distance = row.value<float>("distance", 1);
	if (distance < 0) throw std::runtime_error("row distance must be positive");

	std::vector<std::shared_ptr<Enemy>> newEnemies;
	for (const auto& enemy: row.at("enemies")) {
		newEnemies.emplace_back(parseEnemy(enemy));
	}

	y += distance * 0.25f;
	positionRow(newEnemies, y);

	return newEnemies;
}

std::shared_ptr<SI::model::Enemy> SI::model::Wave::parseEnemy(const nlohmann::json& enemy) {
	auto type = enemy.value<std::string>("type", "default");
	auto coolDown = enemy.value<float>("cooldown", 1);
	auto speed = enemy.value<float>("speed", 1);
	auto size = enemy.value<std::array<float, 2>>("size", {1, 1});
	auto lives = enemy.value<float>("lives", 1);
	auto bulletSpeed = enemy.value<float>("bulletspeed", 1);
	if (bulletSpeed < 0) throw std::runtime_error("bullet speed must be positive");
	auto score = enemy.value<float>("score", 1);

	std::shared_ptr<Enemy> newEnemy;
	if (type == "default") {
		newEnemy = std::make_shared<Enemy>();
	} else {
		throw std::runtime_error("type '" + type + "' is not recognised");
	}

	newEnemy->setBulletSpeed(newEnemy->getBulletSpeed() * bulletSpeed);
	newEnemy->setCoolDown(static_cast<int>(std::round(static_cast<float>(newEnemy->getCoolDown()) * coolDown)));
	newEnemy->setVelocity(newEnemy->getVelocity() * speed);
	newEnemy->setSize({newEnemy->getSize().x * size[0], newEnemy->getSize().y * size[1]});
	newEnemy->setLives(static_cast<unsigned int>(static_cast<float>(newEnemy->getLives()) * lives));
	newEnemy->setValue(static_cast<int>(static_cast<float>(newEnemy->getValue()) * score));

	return newEnemy;
}

void SI::model::Wave::positionRow(const std::vector<std::shared_ptr<Enemy>>& row, float& y) {
	float fullWidth = 0;
	float maxHeight = 0;

	for (const auto& enemy: row) {
		fullWidth += enemy->getSize().x;
		maxHeight = std::max(maxHeight, enemy->getSize().y);
	}

	y += maxHeight / 2;

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

uint8_t SI::model::Wave::getOpacity() const {
	return opacity;
}