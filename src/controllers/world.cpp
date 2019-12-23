//
// Created by ward on 12/3/19.
//

#include "world.h"

SI::controller::World::World(std::shared_ptr<model::World> model, std::shared_ptr<view::World> view)
    : model(std::move(model)), view(std::move(view)), running(true)
{
}

void SI::controller::World::reset() { entities.clear(); }

void SI::controller::World::update()
{
        utils::Event event{};
        while (view->pollEvent(event)) {
                switch (event.type) {
                case utils::Event::closed:
                        running = false;
                        break;
                case utils::Event::keyPressed:
                        switch (event.key) {
                        case utils::Key::escape:
                                if (model->getState() == model::World::State::running)
                                        model->setState(model::World::State::pause);
                                break;
                        case utils::Key::enter:
                                if (model->getState() == model::World::State::victory ||
                                    model->getState() == model::World::State::defeat) {
                                        reset();
                                        model->reset();
                                        view->reset();
                                } else
                                        model->setState(model::World::State::running);
                                break;
                        default:
                                break;
                        }
                        break;
                }
        }

        if (model->getState() != model::World::State::running)
                return;
        for (const auto& entity : entities) {
                entity->update();
        }
}

void SI::controller::World::addEntity(const std::shared_ptr<Entity>& entity)
{
        if (entity == nullptr)
                return;
        entities.emplace(entity);
}

void SI::controller::World::removeEntities()
{
        for (auto it = entities.begin(); it != entities.end();) {
                if ((*it)->mayDeleteThis())
                        it = entities.erase(it);
                else
                        ++it;
        }
}

bool SI::controller::World::isRunning() const { return running; }