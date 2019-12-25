//
// Created by ward on 12/3/19.
//

#include "world.h"
#include "shield.h"

SI::model::World::World() : state(State::start) { reset(); }

void SI::model::World::reset()
{
        setState(State::start);
        Enemy::reset();

        entities.clear();
        physicalEntities.clear();
        getNewModels();

        auto newPlayer = std::make_shared<model::Player>();
        auto newWave = std::make_shared<model::Wave>();
        player = newPlayer;
        wave = newWave;
        addModel(newPlayer);
        addModel(newWave);
        addModel(std::make_shared<model::Shield>(utils::Vector{0, -1.75f}));
        addModel(std::make_shared<model::Shield>(utils::Vector{2, -1.75f}));
        addModel(std::make_shared<model::Shield>(utils::Vector{-2, -1.75f}));
}

void SI::model::World::update()
{
        if (state == State::defeat || state == State::victory) {
                for (const auto& entity : physicalEntities) {
                        entity->deleteThis();
                }
                if (auto w = wave.lock())
                        w->deleteThis();
        } else {
                if (!wave.lock())
                        setState(State::victory);
                if (!player.lock())
                        setState(State::defeat);
                if (Enemy::hasHitGround())
                        setState(State::defeat);
        }

        if (state == State::start || state == State::pause)
                return;

        for (const auto& entity : entities) {
                entity->update();
        }

        for (auto it0 = physicalEntities.begin(); it0 != physicalEntities.end(); ++it0) {
                auto& entity0 = (*it0);
                auto it1 = it0;
                ++it1;
                for (; it1 != physicalEntities.end(); ++it1) {
                        auto& entity1 = (*it1);
                        if (!entity0->collidesWith(entity1) || !entity1->collidesWith(entity0))
                                continue;
                        entity0->onCollision(entity1);
                        entity1->onCollision(entity0);
                }
        }
}

void SI::model::World::addEntity(const std::shared_ptr<Entity>& entity)
{
        if (entity == nullptr)
                return;
        if (auto physicalEntity = std::dynamic_pointer_cast<PhysicalEntity>(entity))
                physicalEntities.emplace(physicalEntity);
        entities.emplace(entity);
}

std::vector<std::shared_ptr<SI::model::Entity>> SI::model::World::getNewModels()
{
        for (const auto& entity : entities) {
                addModels(entity->getNewModels());
        }
        return Entity::getNewModels();
}

void SI::model::World::removeEntities()
{
        for (auto it = entities.begin(); it != entities.end();) {
                if ((*it)->mayDeleteThis())
                        it = entities.erase(it);
                else
                        ++it;
        }
        for (auto it = physicalEntities.begin(); it != physicalEntities.end();) {
                if ((*it)->mayDeleteThis())
                        it = physicalEntities.erase(it);
                else
                        ++it;
        }
}

const std::weak_ptr<SI::model::Player>& SI::model::World::getPlayer() const { return player; }

const std::weak_ptr<SI::model::Wave>& SI::model::World::getWave() const { return wave; }

SI::model::World::State SI::model::World::getState() const { return state; }

void SI::model::World::setState(SI::model::World::State newState)
{
        World::state = newState;
        notifyObservers();
}