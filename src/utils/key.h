//
// Created by ward on 12/3/19.
//

#ifndef SPACEINVADERS_KEY_H
#define SPACEINVADERS_KEY_H

namespace utils {

/**
 * custom key class to not be dependent on SFML keys
 */
enum class Key
{
        up,
        down,
        left,
        right,
        space,
        escape,
        enter
};

} // namespace utils

#endif // SPACEINVADERS_KEY_H
