//
// Created by ward on 12/22/19.
//

#include "assets.h"

utils::Assets& utils::Assets::get()
{
        static Assets assets;
        return assets;
}

utils::Assets::Assets()
    : music(std::make_shared<sf::Music>()), bold(std::make_shared<sf::Font>()), normal(std::make_shared<sf::Font>())
{
        if (!music->openFromFile("data/audio/The_Cannery.wav"))
                throw std::runtime_error("The_Cannery.wav must be present in data/audio");
        if (!bold->loadFromFile("data/fonts/tf2build.ttf"))
                throw std::runtime_error("tf2build.ttf must be present in data/fonts");
        if (!normal->loadFromFile("data/fonts/TF2secondary.ttf"))
                throw std::runtime_error("TF2secondary.ttf must be present in data/fonts");
}

const std::shared_ptr<sf::Music>& utils::Assets::getMusic() const { return music; }

const std::shared_ptr<sf::Font>& utils::Assets::getBold() const { return bold; }

const std::shared_ptr<sf::Font>& utils::Assets::getNormal() const { return normal; }
