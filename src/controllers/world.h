//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_WORLDCONTROLLER_H
#define SPACEINVADERS_WORLDCONTROLLER_H

#include "../views/world.h"
#include "entity.h"

namespace SI::controller {
/**
 * controller class for the world
 */
class World : public Entity
{
public:
        /**
         * construct with correct model and view
         * @param model pointer
         * @param view pointer
         */
        World(std::shared_ptr<model::World> model, std::shared_ptr<view::World> view);

        /**
         * reset the world controller
         */
        void reset();

        /**
         * update the controller with user events
         */
        void update() final;

        /**
         * add a new controller to the world
         * @param entity new controller
         */
        void addEntity(const std::shared_ptr<Entity>& entity);

        /**
         * remove all controllers that may be deleted
         */
        void removeEntities();

        /**
         * whether the game may be closed
         * @return true if running
         */
        bool isRunning() const;

        ~World() final = default;

private:
        const std::shared_ptr<model::World> model;
        const std::shared_ptr<view::World> view;
        std::unordered_set<std::shared_ptr<Entity>> entities;

        bool running;
};

} // namespace SI::controller

#endif // SPACEINVADERS_WORLDCONTROLLER_H
