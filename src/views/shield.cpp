//
// Created by ward on 12/19/19.
//

#include "shield.h"
#include "../utils/transformation.h"

SI::view::Shield::Shield(const std::weak_ptr<model::Shield>& model, const std::shared_ptr<sf::RenderWindow>& window)
    : PhysicalEntity(model, window)
{
        sprite.setFillColor(sf::Color(106, 128, 150));
        sprite.setSize(utils::Transformation::get().convertDistance<float>(model::Shield::ShieldSegment::size() /
                                                                           model::Shield::ShieldSegment::amount));
        notify();
}

void SI::view::Shield::notify() {}

void SI::view::Shield::update()
{
        auto model = std::dynamic_pointer_cast<model::Shield>(lock());
        if (mayDeleteThis())
                return;

        for (size_t x0 = 0; x0 < model->getSegments().size(); ++x0) {
                const auto& row0 = model->getSegments()[x0];
                for (size_t y0 = 0; y0 < row0.size(); ++y0) {
                        const auto& segment = row0[y0];
                        for (size_t x1 = 0; x1 < segment.points.size(); ++x1) {
                                const auto& row1 = segment.points[x1];
                                for (size_t y1 = 0; y1 < row1.size(); ++y1) {
                                        const auto& point = row1[y1];
                                        if (!point)
                                                continue;

                                        const auto pos = model->convert(static_cast<int>(x0), static_cast<int>(y0),
                                                                        static_cast<int>(x1), static_cast<int>(y1));
                                        sprite.setPosition(utils::Transformation::get().convertPoint<float>(pos));
                                        window->draw(sprite);
                                }
                        }
                }
        }
}

int SI::view::Shield::drawOrder() { return 1; }