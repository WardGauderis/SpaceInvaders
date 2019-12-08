//
// Created by ward on 12/2/19.
//

#include <cmath>

#include "vector.h"

utils::Vector::Vector() : Vector(0, 0) {}

utils::Vector::Vector(float x, float y) : x(x), y(y) {}

float utils::Vector::length() const {
	return std::sqrt(std::pow(x, 2.0f) + std::pow(y, 2.0f));
}

utils::Vector utils::Vector::normalize(const utils::Vector vector) {
	return vector / vector.length();
}

utils::Vector utils::Vector::operator-() const {
	return {-x, -y};
}

utils::Vector& utils::Vector::operator+=(const Vector vector) {
	x += vector.x;
	y += vector.y;
	return *this;
}

utils::Vector& utils::Vector::operator-=(utils::Vector vector) {
	x -= vector.x;
	y -= vector.y;
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

utils::Vector utils::Vector::operator*(float amount) const {
	return {x * amount, y * amount};
}

utils::Vector utils::Vector::operator/(float amount) const {
	return {x / amount, y / amount};
}