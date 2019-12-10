//
// Created by ward on 12/2/19.
//

#include "spaceShip.h"

SI::controller::SpaceShip::SpaceShip(const std::weak_ptr<model::SpaceShip>& model,
                                     const std::weak_ptr<view::SpaceShip>& view) : PhysicalEntity(model, view) {}
