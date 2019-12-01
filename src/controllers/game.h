//
// Created by ward on 12/1/19.
//

#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

namespace SI::controller {

	class Game {
	public:
		[[nodiscard]] bool isRunning() const;

	private:
		bool running;
	};

}

#endif //SPACEINVADERS_GAME_H
