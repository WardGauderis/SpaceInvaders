//
// Created by ward on 12/2/19.
//

#include "spaceShip.h"

void SI::controller::SpaceShip::handleInput() {

}

SI::controller::SpaceShip::SpaceShip(const std::shared_ptr<view::View>& view,
                                     const std::shared_ptr<model::Entity>& model) : Entity(view, model) {}
