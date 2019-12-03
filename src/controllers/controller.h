//
// Created by ward on 12/2/19.
//

#ifndef SPACEINVADERS_CONTROLLER_H
#define SPACEINVADERS_CONTROLLER_H

#include <memory>

#include "../models/model.h"

namespace SI::controller {

	class Controller {
	public:
		virtual void handleInput() = 0;

		virtual ~Controller() = default;

	private:
		std::shared_ptr<model::Model> model;

	};

}


#endif //SPACEINVADERS_CONTROLLER_H
