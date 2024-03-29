//
// Created by ward on 12/3/19.
//

#include "world.h"

#include "../utils/assets.h"
#include "../utils/transformation.h"
#include "display.h"

SI::view::World::World(std::shared_ptr<model::World> model)
    : Entity(), model(std::move(model)),
      entities([](const std::shared_ptr<SI::view::Entity>& entity0, const std::shared_ptr<SI::view::Entity>& entity1) {
              if (entity0->drawOrder() == entity1->drawOrder())
                      return entity0 < entity1;
              else
                      return entity0->drawOrder() < entity1->drawOrder();
      })
{
        utils::Assets::get().getMusic()->setLoop(true);

        sf::ContextSettings settings;
        settings.antialiasingLevel = 8;

        window = std::make_shared<sf::RenderWindow>(
            sf::VideoMode(utils::Transformation::get().getWidth(), utils::Transformation::get().getHeight()),
            "Space Invaders", sf::Style::Close, settings);
        window->setKeyRepeatEnabled(false);

        dim.setSize(utils::Transformation::get().convertDistance<float>({8, 6}));
        dim.setPosition(utils::Transformation::get().convertPoint<float>({-4, -3}));
        dim.setFillColor(sf::Color(10, 10, 10, 150));

        instruction.setFont(*utils::Assets::get().getNormal());
        auto size = utils::Transformation::get().convertDistance<unsigned int>({0.25f, 0}).x;
        instruction.setCharacterSize(size);
        centerText(instruction, "Press Enter to continue", {0, -1});
        instruction.setFillColor(sf::Color(245, 231, 222));

        head.setFont(*utils::Assets::get().getBold());
        size = utils::Transformation::get().convertDistance<unsigned int>({0.75f, 0}).x;
        head.setCharacterSize(size);
        head.setOutlineThickness(static_cast<float>(utils::Transformation::get().getWidth()) / 120.0f);
        head.setFillColor(sf::Color(245, 231, 222));

        reset();
}

void SI::view::World::reset()
{
        entities.clear();
        auto newDisplay = std::make_shared<view::Display>(getWindow(), model->getPlayer(), model->getWave());
        auto player = model->getPlayer().lock();
        player->addObserver(newDisplay);
        auto wave = model->getWave().lock();
        wave->addObserver(newDisplay);
        addEntity(newDisplay);
        notify();
}

void SI::view::World::notify()
{
        switch (model->getState()) {
        case model::World::State::running:
                utils::Assets::get().getMusic()->pause();
                utils::Assets::get().getMusic()->play();
                break;
        case model::World::State::pause:
                utils::Assets::get().getMusic()->pause();
                head.setOutlineColor(sf::Color(11, 69, 100));
                centerText(head, "PAUSE", {0, 1.5f});
                break;
        case model::World::State::victory:
                head.setOutlineColor(sf::Color(43, 143, 200));
                centerText(head, "VICTORY", {0, 1.5f});
                break;
        case model::World::State::defeat:
                head.setOutlineColor(sf::Color(200, 43, 43));
                centerText(head, "DEFEAT", {0, 1.5f});
                break;
        case model::World::State::start:
                utils::Assets::get().getMusic()->pause();
                utils::Assets::get().getMusic()->play();
                head.setOutlineColor(sf::Color(11, 69, 100));
                centerText(head, "SPACE QUBES", {0, 1.5f});
                break;
        }
}

void SI::view::World::update()
{
        window->clear(sf::Color(30, 27, 25));

        for (const auto& entity : entities) {
                entity->update();
        }

        if (model->getState() != model::World::State::running) {
                window->draw(dim);
                window->draw(instruction);
                window->draw(head);
        }

        window->display();
}

void SI::view::World::addEntity(const std::shared_ptr<Entity>& entity)
{
        if (entity == nullptr)
                return;
        entities.emplace(entity);
}

void SI::view::World::removeEntities()
{
        for (auto it = entities.begin(); it != entities.end();) {
                if ((*it)->mayDeleteThis())
                        it = entities.erase(it);
                else
                        ++it;
        }
}

std::shared_ptr<sf::RenderWindow> SI::view::World::getWindow() const { return window; }
