//
// Created by ward on 11/28/19.
//

#include <cmath>
#include "transformation.h"

Transformation& Transformation::instance() {
	static Transformation transformation;
	return transformation;
}

void Transformation::setDimensions(const unsigned int x, const unsigned int y) {
	width = x;
	height = y;
}

unsigned int Transformation::convertWidth(float x) {
	return static_cast<unsigned int>(std::round((x / 8.0f + 0.5f) * static_cast<float>(width)));
}

unsigned int Transformation::convertHeight(float y) {
	return static_cast<unsigned int>(std::round((y / 6.0f + 0.5f) * static_cast<float>(height)));
}

float Transformation::convertWidth(unsigned int x) {
	return (static_cast<float>(x) / static_cast<float>(width) - 0.5f) * 8.0f;
}

float Transformation::convertHeight(unsigned int y) {
	return (static_cast<float>(y) / static_cast<float>(height) - 0.5f) * 6.0f;
}
