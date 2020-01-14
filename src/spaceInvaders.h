//
// Created by ward on 11/19/19.
//

#ifndef SPACEINVADERS_SPACEINVADERS_H
#define SPACEINVADERS_SPACEINVADERS_H

#include "controllers/world.h"

/**
 * Space Invaders namespace
 */
namespace SI {

/**
 * class that contains the MVC worlds
 */
class SpaceInvaders
{
public:
        /**
         * constructs the MVC worlds correctly
         */
        SpaceInvaders();

        /**
         * updates the MVC worlds such that the updates of model en controller are constant (60 updates per second)
         * and the updates of view try to reach 60 fps
         */
        void eventLoop();

private:
        const std::shared_ptr<model::World> model;
        const std::shared_ptr<view::World> view;
        const std::unique_ptr<controller::World> controller;

        /**
         * removes controllers and updates the remaining
         */
        void updateController();

        /**
         * updates the models, adds new MVC entities and removes models
         */
        void updateModel();

        /**
         * removes views and updates the remaining
         */
        void updateView();

        /**
         * given a model, the game adds the necessary views and controllers correctly to the MVC worlds
         * @param entityModel input model
         * @return weak_ptr to input model
         */
        std::weak_ptr<model::Entity> addEntity(const std::shared_ptr<model::Entity>& entityModel);
};

} // namespace SI

#endif // SPACEINVADERS_SPACEINVADERS_H
