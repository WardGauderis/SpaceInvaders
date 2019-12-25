//
// Created by ward on 12/3/19.
//

#include "player.h"

int SI::model::Player::score = 0;

SI::model::Player::Player() : SpaceShip(0.9f, {0.5f, 0.5f}, {0, -2.5f}, {0, 0}, 10, 0.05f, true), timer(20)
{
        resetScore();
}

void SI::model::Player::update()
{
        timer.update();
        SpaceShip::update();
}

bool SI::model::Player::shoot()
{
        if (!timer.ready())
                return false;
        return SpaceShip::shoot(true);
}

unsigned int SI::model::Player::loseLive()
{
        auto backupVelocity = velocity;
        addVelocity({0, 0.05f});
        SpaceShip::loseLive();
        velocity = backupVelocity;
        return getLives();
}

int SI::model::Player::getScore() { return score; }

void SI::model::Player::addScore(int points) { Player::score += points; }

void SI::model::Player::resetScore() { score = 0; }
