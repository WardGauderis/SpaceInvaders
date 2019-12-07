//
// Created by ward on 11/28/19.
//

#include <cmath>

#include "transformation.h"

utils::Transformation& utils::Transformation::get() {
	static Transformation transformation;
	return transformation;
}

void utils::Transformation::setDimensions(const unsigned int x, const unsigned int y) {
	width = x;
	height = y;
}

int utils::Transformation::convertWidth(const float x) const {
	return static_cast<int>(std::round((x / 8.0f + 0.5f) * static_cast<float>(width)));
}

int utils::Transformation::convertHeight(const float y) const {
	return static_cast<int>(std::round((y / -6.0f + 0.5f) * static_cast<float>(height)));
}

float utils::Transformation::convertWidth(const int x) const {
	return (static_cast<float>(x) / static_cast<float>(width) - 0.5f) * 8.0f;
}

float utils::Transformation::convertHeight(const int y) const {
	return (static_cast<float>(y) / static_cast<float>(height) - 0.5f) * 6.0f;
}

sf::Vector2i utils::Transformation::convert(const utils::Vector vector) const {
	return {convertWidth(vector.x), convertHeight(vector.y)};
}

utils::Vector utils::Transformation::convert(const sf::Vector2i vector) const {
	return {convertWidth(vector.x), convertHeight(vector.y)};
}
