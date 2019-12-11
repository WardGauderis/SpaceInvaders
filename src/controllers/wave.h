//
// Created by ward on 12/9/19.
//

#ifndef SPACEINVADERS_WAVECONTROLLER_H
#define SPACEINVADERS_WAVECONTROLLER_H

#include <unordered_set>
#include "enemy.h"
#include "../views/wave.h"

namespace SI::controller {

	class Wave : public Entity {
	public:
		Wave(std::weak_ptr<model::Wave> model, std::weak_ptr<view::Wave> view);

		void update() override;

		~Wave() override = default;

	private:
		std::weak_ptr<model::Wave> model;
		std::weak_ptr<view::Wave> view;
		std::unordered_set<std::shared_ptr<Enemy>> enemies;
	};

}

#endif //SPACEINVADERS_WAVECONTROLLER_H
