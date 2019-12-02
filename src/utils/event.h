//
// Created by ward on 12/2/19.
//

#ifndef SPACEINVADERS_EVENT_H
#define SPACEINVADERS_EVENT_H

namespace utils {

	enum class Key {
		up,
		down,
		left,
		right
	};

	struct Event {

		struct KeyEvent {
			Key code;
		};

		enum EventType {
			Closed,
			KeyPressed
		};

		EventType type;

		union {
			KeyEvent key;
		};

	};

}

#endif //SPACEINVADERS_EVENT_H
