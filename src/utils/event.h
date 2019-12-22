//
// Created by ward on 12/2/19.
//

#ifndef SPACEINVADERS_EVENT_H
#define SPACEINVADERS_EVENT_H

namespace utils {

	struct Event {

		enum EventType {
			closed,
			keyPressed
		};

		EventType type;
		union {
			Key key;
		};
	};

}

#endif //SPACEINVADERS_EVENT_H
