//
// Created by ward on 11/28/19.
//

#include "transformation.h"

utils::Transformation& utils::Transformation::get() {
	static Transformation transformation;
	return transformation;
}

void utils::Transformation::setDimensions(const unsigned int x, const unsigned int y) {
	width = x;
	height = y;
}

unsigned int utils::Transformation::getWidth() const {
	return width;
}

unsigned int utils::Transformation::getHeight() const {
	return height;
}

template<typename T>
T utils::Transformation::convertWidth(const float x) const {
	return static_cast<T>((x / 8.0f) * static_cast<float>(width));
}

template int utils::Transformation::convertWidth<int>(float x) const;

template float utils::Transformation::convertWidth<float>(float x) const;

template<typename T>
T utils::Transformation::convertHeight(const float y) const {
	return static_cast<T>((-y / 6.0f) * static_cast<float>(height));
}

template int utils::Transformation::convertHeight(float x) const;

template float utils::Transformation::convertHeight(float x) const;

//float utils::Transformation::convertWidth(const int x) const {
//	return (static_cast<float>(x) / static_cast<float>(width) - 0.5f) * 8.0f;
//}

//float utils::Transformation::convertHeight(const int y) const {
//	return (static_cast<float>(y) / static_cast<float>(height) - 0.5f) * 6.0f;
//}

template<typename T>
sf::Vector2<T> utils::Transformation::convertPoint(const utils::Vector vector) const {
	return sf::Vector2<T>(convertWidth<T>(vector.x) + T(width) / 2, convertHeight<T>(vector.y) + T(height) / 2);
}

template sf::Vector2<int> utils::Transformation::convertPoint(const Vector vector) const;

template sf::Vector2<float> utils::Transformation::convertPoint(const Vector vector) const;

template<typename T>
sf::Vector2<T> utils::Transformation::convertDistance(const utils::Vector vector) const {
	return sf::Vector2<T>(convertWidth<T>(vector.x), convertHeight<T>(vector.y));
}

template sf::Vector2<int> utils::Transformation::convertDistance(const Vector vector) const;

template sf::Vector2<float> utils::Transformation::convertDistance(const Vector vector) const;

//utils::Vector utils::Transformation::convert(const sf::Vector2i vector) const {
//	return {convertWidth(vector.x), convertHeight(vector.y)};
//}
