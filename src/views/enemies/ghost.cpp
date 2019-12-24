//
// Created by ward on 12/24/19.
//

#include "ghost.h"
#include "../../utils/assets.h"
#include "../../utils/transformation.h"

SI::view::Ghost::Ghost(const std::weak_ptr<model::Ghost>& model, const std::shared_ptr<sf::RenderWindow>& window)
    : Enemy(model, window, utils::Assets::get().getGhost())
{
}

void SI::view::Ghost::notify()
{
        auto m = lock();
        if (mayDeleteThis())
                return;

        auto opacity = std::dynamic_pointer_cast<model::Ghost>(m)->getOpacity();
        sign.setFillColor(sf::Color(255, 255, 255, opacity));
        auto color = sprite.getFillColor();
        color.a = opacity;
        sprite.setFillColor(color);
        color = sprite.getOutlineColor();
        color.a = static_cast<float>(opacity) / 255.0f * 100.0f;
        sprite.setOutlineColor(color);
        Enemy::notify();
}