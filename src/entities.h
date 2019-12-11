//
// Created by ward on 12/7/19.
//

#ifndef SPACEINVADERS_ENTITIES_H
#define SPACEINVADERS_ENTITIES_H

#endif //SPACEINVADERS_ENTITIES_H

#include "controllers/player.h"
#include "controllers/bullet.h"
#include "controllers/enemy.h"
#include "controllers/wave.h"

namespace SI {

	struct Player {
		using Model = model::Player;
		using View = view::Player;
		using Controller = controller::Player;
	};

	struct Enemy {
		using Model = model::Enemy;
		using View = view::Enemy;
		using Controller = controller::Enemy;
	};

	struct Wave {
		using Model = model::Wave;
		using View = view::Wave;
		using Controller = controller::Wave;
	};

	struct Bullet {
		using Model = model::Bullet;
		using View = view::Bullet;
		using Controller = controller::Bullet;
	};

}