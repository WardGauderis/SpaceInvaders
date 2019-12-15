//
// Created by ward on 12/2/19.
//

#ifndef SPACEINVADERS_VECTOR_H
#define SPACEINVADERS_VECTOR_H

namespace utils {

	struct Vector {
		float x;
		float y;

		Vector();

		Vector(float x, float y);

		explicit operator bool();

		[[nodiscard]] float length() const;

		Vector normalize() const;

		Vector rotate(const float angle) const;

		[[nodiscard]] float dot(Vector vector) const;

		Vector operator-() const;

		Vector& operator+=(Vector vector);

		Vector& operator-=(Vector vector);

		Vector& operator*=(float amount);

		Vector operator+(Vector vector) const;

		Vector operator-(Vector vector) const;

		Vector operator*(float amount) const;

		Vector operator/(float amount) const;

		Vector operator+(float amount) const;
	};

	float getSign(float);

}


#endif //SPACEINVADERS_VECTOR_H
