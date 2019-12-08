//
// Created by ward on 12/2/19.
//

#include "spaceShip.h"

SI::controller::SpaceShip::SpaceShip(const std::shared_ptr<model::SpaceShip>& model,
                                     const std::shared_ptr<view::SpaceShip>& view) : PhysicalEntity(model, view) {}

void SI::controller::SpaceShip::update(SpaceInvaders& game) {

}