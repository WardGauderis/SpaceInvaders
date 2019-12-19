//
// Created by ward on 12/15/19.
//

#include "display.h"
#include "../utils/transformation.h"


SI::view::Display::Display(const std::shared_ptr<sf::RenderWindow>& window, std::weak_ptr<model::Player> playerModel,
                           std::weak_ptr<model::Wave> waveModel) : Entity(window), playerModel(std::move(playerModel)),
                                                                   waveModel(std::move(waveModel)) {
	if (!font.loadFromFile("data/fonts/TF2secondary.ttf"))
		throw std::runtime_error("TF2secondary.ttf must be present in data/fonts");

	bar.setPosition(utils::Transformation::get().convertPoint<float>({-4, -3}));
	bar.setSize(utils::Transformation::get().convertDistance<float>({8, 0.25}));
	bar.setFillColor(sf::Color(50, 49, 47));

	lives.setFont(font);
	waveNumber.setFont(font);
	score.setFont(font);

	auto size = utils::Transformation::get().convertDistance<unsigned int>({0.25, 0}).x;
	lives.setCharacterSize(size);
	waveNumber.setCharacterSize(size);
	score.setCharacterSize(size);

	auto color = sf::Color(245, 231, 222);
	lives.setFillColor(color);
	waveNumber.setFillColor(color);
	score.setFillColor(color);
	notify();
}

void SI::view::Display::notify() {
	auto[player, wave] = lock();
	if(mayDeleteThis()) return;
	lives.setString("Lives: " + std::to_string(player->getLives()));
	waveNumber.setString("Wave " + std::to_string(wave->getWaveNumber()));
	score.setString("Score: " + std::to_string(model::Enemy::getScore()));

	auto box = lives.getLocalBounds();
	lives.setOrigin(box.left, box.top + box.height / 2);
	lives.setPosition(utils::Transformation::get().convertPoint<float>({-3.9f, -3 +0.125f}));

	box = waveNumber.getLocalBounds();
	waveNumber.setOrigin(box.left + box.width / 2, box.top + box.height / 2);
	waveNumber.setPosition(utils::Transformation::get().convertPoint<float>({0, -3 + 0.125f}));

	box = score.getLocalBounds();
	score.setOrigin(box.left + box.width, box.top + box.height / 2);
	score.setPosition(utils::Transformation::get().convertPoint<float>({3.9f, -3 + 0.125f}));
}

void SI::view::Display::update() {
	window->draw(bar);
	window->draw(lives);
	window->draw(waveNumber);
	window->draw(score);
}

int SI::view::Display::drawOrder() {
	return 2;
}

std::pair<std::shared_ptr<SI::model::Player>, std::shared_ptr<SI::model::Wave>> SI::view::Display::lock() {
	auto player = playerModel.lock();
	auto wave = waveModel.lock();	if (!player || !wave || player->mayDeleteThis() || wave->mayDeleteThis()) deleteThis();
	return {player, wave};
}