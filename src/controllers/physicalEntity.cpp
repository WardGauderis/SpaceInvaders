//
// Created by ward on 12/8/19.
//

#include "physicalEntity.h"

#include <utility>

SI::controller::PhysicalEntity::PhysicalEntity(std::shared_ptr<model::PhysicalEntity> model,
                                               std::shared_ptr<view::PhysicalEntity> view) : model(std::move(model)),
                                                                                             view(std::move(view)) {}
