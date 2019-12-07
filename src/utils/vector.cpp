//
// Created by ward on 12/2/19.
//

#include "vector.h"

utils::Vector& utils::Vector::operator+=(const Vector& vector) {
	x += vector.x;
	y += vector.y;
	return *this;
}

utils::Vector& utils::Vector::operator*=(float amount) {
	x *= amount;
	y *= amount;
	return *this;
}
