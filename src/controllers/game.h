//
// Created by ward on 12/1/19.
//

#ifndef SPACEINVADERS_GAMECONTROLLER_H
#define SPACEINVADERS_GAMECONTROLLER_H

namespace SI::controller {

	class Game {
	public:
		Game();

		[[nodiscard]] bool isRunning() const;

	private:
		bool running;
	};

}

#endif //SPACEINVADERS_GAMECONTROLLER_H
