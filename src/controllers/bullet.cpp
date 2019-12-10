//
// Created by ward on 12/8/19.
//

#include "bullet.h"

SI::controller::Bullet::Bullet(const std::weak_ptr<model::Bullet>& model,
                               const std::weak_ptr<view::Bullet>& view) : PhysicalEntity(model, view) {}
