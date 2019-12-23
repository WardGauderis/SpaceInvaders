//
// Created by ward on 12/2/19.
//

#ifndef SPACEINVADERS_EVENT_H
#define SPACEINVADERS_EVENT_H

namespace utils {

	/**
	 * custom event class to not be dependent on SFML events
	 */
	struct Event {

		enum EventType {
			closed,
			keyPressed
		};

		EventType type;
		Key key;
	};

}

#endif //SPACEINVADERS_EVENT_H
