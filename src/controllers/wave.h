//
// Created by ward on 12/9/19.
//

#ifndef SPACEINVADERS_WAVECONTROLLER_H
#define SPACEINVADERS_WAVECONTROLLER_H

#include "enemy.h"
#include "../views/wave.h"

namespace SI::controller {

	class Wave : public Entity {
	public:
		Wave(std::weak_ptr<model::Wave> model, std::weak_ptr<view::Wave> view);

		void update() override;

		std::pair<std::shared_ptr<model::Wave>, std::shared_ptr<view::Wave>> lock();

		~Wave() override = default;

	private:
		std::weak_ptr<model::Wave> model;
		std::weak_ptr<view::Wave> view;
	};

}

#endif //SPACEINVADERS_WAVECONTROLLER_H
