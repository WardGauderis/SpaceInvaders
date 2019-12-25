//
// Created by ward on 12/24/19.
//

#include "ghost.h"
#include "../bullet.h"

SI::model::Ghost::Ghost() : state(Visibility::invisible), timer(stable)
{
        setValue(20);
        setBulletSpeed(0.07f);
        setCoolDown(60);
        setVelocity({0.02f, 0});
        timer.reset();
}

void SI::model::Ghost::update()
{
        if (timer.ready()) {
                switch (state) {
                case Visibility::visible:
                        state = Visibility::disappearing;
                        timer = utils::Timer(transition);
                        break;
                case Visibility::invisible:
                        state = Visibility::appearing;
                        timer = utils::Timer(transition);
                        break;
                case Visibility::appearing:
                        state = Visibility::visible;
                        timer = utils::Timer(stable);
                        break;
                case Visibility::disappearing:
                        state = Visibility::invisible;
                        timer = utils::Timer(stable);
                        break;
                }
                timer.reset();
        }
        Enemy::update();
        if (detectWallCollision().y == 3)
                return;
        timer.update();
}

bool SI::model::Ghost::collidesWith(const std::shared_ptr<PhysicalEntity>& entity)
{
        if (state != Visibility::visible && std::dynamic_pointer_cast<Bullet>(entity)) {
                return false;
        }
        return PhysicalEntity::collidesWith(entity);
}

bool SI::model::Ghost::shoot()
{
        if (state != Visibility::visible)
                return false;
        return Enemy::shoot();
}

uint8_t SI::model::Ghost::getOpacity() const
{
        uint8_t opacity = 0;
        switch (state) {
        case Visibility::visible:
                opacity = 255;
                break;
        case Visibility::invisible:
                opacity = 0;
                break;
        case Visibility::appearing:
                opacity = static_cast<uint8_t>((1 - static_cast<float>(timer.getTime()) / transition) * 255);
                break;
        case Visibility::disappearing:
                opacity = static_cast<uint8_t>((static_cast<float>(timer.getTime()) / transition) * 255);
                break;
        }
        return opacity;
}