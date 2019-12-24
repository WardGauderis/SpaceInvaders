//
// Created by ward on 11/28/19.
//

#include "transformation.h"

utils::Transformation& utils::Transformation::get()
{
        static Transformation transformation;
        return transformation;
}

void utils::Transformation::setDimensions(const unsigned int x, const unsigned int y)
{
        width = x;
        height = y;
}

unsigned int utils::Transformation::getWidth() const { return width; }

unsigned int utils::Transformation::getHeight() const { return height; }

template <typename T>
sf::Vector2<T> utils::Transformation::convertPoint(const utils::Vector vector) const
{
        return sf::Vector2<T>(convertWidth<T>(vector.x) + static_cast<T>(width) / 2,
                              convertHeight<T>(vector.y) + static_cast<T>(height) / 2);
}

template sf::Vector2<int> utils::Transformation::convertPoint(const Vector vector) const;

template sf::Vector2<unsigned int> utils::Transformation::convertPoint(const Vector vector) const;

template sf::Vector2<float> utils::Transformation::convertPoint(const Vector vector) const;

template <typename T>
sf::Vector2<T> utils::Transformation::convertDistance(const utils::Vector vector) const
{
        return sf::Vector2<T>(convertWidth<T>(vector.x), convertHeight<T>(vector.y));
}

template sf::Vector2<int> utils::Transformation::convertDistance(const Vector vector) const;

template sf::Vector2<unsigned int> utils::Transformation::convertDistance(const Vector vector) const;

template sf::Vector2<float> utils::Transformation::convertDistance(const Vector vector) const;

template <typename T>
utils::Vector utils::Transformation::convertPointBack(sf::Vector2<T> vector) const
{
        return {convertWidthBack(vector.x) - static_cast<float>(width) / 2,
                convertHeightBack(vector.y) - static_cast<float>(width) / 2};
}

template utils::Vector utils::Transformation::convertPointBack(sf::Vector2<int> vector) const;

template utils::Vector utils::Transformation::convertPointBack(sf::Vector2<unsigned int> vector) const;

template utils::Vector utils::Transformation::convertPointBack(sf::Vector2<float> vector) const;

template <typename T>
utils::Vector utils::Transformation::convertDistanceBack(sf::Vector2<T> vector) const
{
        return {convertWidthBack(vector.x), convertHeightBack(vector.y)};
}

template utils::Vector utils::Transformation::convertDistanceBack(sf::Vector2<int> vector) const;

template utils::Vector utils::Transformation::convertDistanceBack(sf::Vector2<unsigned int> vector) const;

template utils::Vector utils::Transformation::convertDistanceBack(sf::Vector2<float> vector) const;

template <typename T>
T utils::Transformation::convertWidth(const float x) const
{
        return static_cast<T>((x / 8.0f) * static_cast<float>(width));
}

template <typename T>
T utils::Transformation::convertHeight(const float y) const
{
        return static_cast<T>((-y / 6.0f) * static_cast<float>(height));
}

template <typename T>
float utils::Transformation::convertWidthBack(T x) const
{
        return (x / static_cast<float>(width)) * 8.0f;
}

template <typename T>
float utils::Transformation::convertHeightBack(T y) const
{
        return (-y / static_cast<float>(height)) * 6.0f;
}
