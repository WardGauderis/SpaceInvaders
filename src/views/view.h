//
// Created by ward on 12/2/19.
//

#ifndef SPACEINVADERS_VIEW_H
#define SPACEINVADERS_VIEW_H

#include <SFML/Graphics.hpp>

#include "../utils/observer.h"

namespace SI::view {

	class View : public utils::Observer {
	public:
		virtual void render() = 0;

	private:

	};

}

#endif //SPACEINVADERS_VIEW_H
