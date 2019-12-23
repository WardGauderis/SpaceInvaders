//
// Created by ward on 12/2/19.
//

#ifndef SPACEINVADERS_EVENT_H
#define SPACEINVADERS_EVENT_H

#include "key.h"

namespace utils {

/**
 * custom event class to not be dependent on SFML events
 */
struct Event
{

        enum EventType
        {
                closed,
                keyPressed
        };

        EventType type;
        Key key;
};

} // namespace utils

#endif // SPACEINVADERS_EVENT_H
