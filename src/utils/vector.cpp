//
// Created by ward on 12/2/19.
//

#include <cmath>

#include "vector.h"

float utils::Vector::length() const {
	return std::sqrt(std::pow(x, 2.0f) + std::pow(y, 2.0f));
}

utils::Vector& utils::Vector::operator+=(const Vector vector) {
	x += vector.x;
	y += vector.y;
	return *this;
}

utils::Vector& utils::Vector::operator*=(float amount) {
	x *= amount;
	y *= amount;
	return *this;
}

utils::Vector utils::Vector::operator+(const utils::Vector vector) const {
	return {x + vector.x, y + vector.y};
}

utils::Vector utils::Vector::operator-(utils::Vector vector) const {
	return {x - vector.x, y - vector.y};
}

utils::Vector utils::Vector::operator/(float amount) const {
	return {x / amount, y / amount};
}

