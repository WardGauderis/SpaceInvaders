//
// Created by ward on 12/8/19.
//

#ifndef SPACEINVADERS_PHYSICALENTITYCONTROLLER_H
#define SPACEINVADERS_PHYSICALENTITYCONTROLLER_H

#include "../views/physicalEntity.h"
#include "entity.h"

namespace SI::controller {
/**
 * controller class for physical entities
 */
class PhysicalEntity : public Entity
{
public:
        /**
         * construct with the correct model and view
         * @param model pointer
         * @param view pointer
         */
        PhysicalEntity(std::weak_ptr<model::PhysicalEntity> model, std::weak_ptr<view::PhysicalEntity> view);

        /**
         * check whether the model and view pointers are still present, otherwise delete this
         * @return shared pointers to model and view
         */
        std::pair<std::shared_ptr<model::PhysicalEntity>, std::shared_ptr<view::PhysicalEntity>> lock();

        ~PhysicalEntity() override = default;

protected:
        const std::weak_ptr<model::PhysicalEntity> model;
        const std::weak_ptr<view::PhysicalEntity> view;
};

} // namespace SI::controller

#endif // SPACEINVADERS_PHYSICALENTITYCONTROLLER_H
