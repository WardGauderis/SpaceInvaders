//
// Created by ward on 12/2/19.
//

#include "spaceShip.h"
#include "../views/spaceShip.h"

void SI::controller::SpaceShip::handleInput() {

}

SI::controller::SpaceShip::SpaceShip(const std::shared_ptr<view::SpaceShip>& view,
                                     const std::shared_ptr<model::SpaceShip>& model) : Entity(view, model) {}
