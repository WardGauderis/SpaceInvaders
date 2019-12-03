//
// Created by ward on 12/1/19.
//

#ifndef SPACEINVADERS_GAMEVIEW_H
#define SPACEINVADERS_GAMEVIEW_H

#include "view.h"
#include "../utils/event.h"

namespace SI::view {

	class Game : public View {
	public:
		Game();

		void render() final;

		void notify() final;

	private:

	};

}

#endif //SPACEINVADERS_GAMEVIEW_H
