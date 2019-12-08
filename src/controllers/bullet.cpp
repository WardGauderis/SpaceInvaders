//
// Created by ward on 12/8/19.
//

#include "bullet.h"

SI::controller::Bullet::Bullet(const std::shared_ptr<model::Bullet>& model,
                               const std::shared_ptr<view::Bullet>& view) : PhysicalEntity(model, view) {}

void SI::controller::Bullet::update(SpaceInvaders& game) {

}