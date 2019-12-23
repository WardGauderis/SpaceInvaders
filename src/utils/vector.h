//
// Created by ward on 12/2/19.
//

#ifndef SPACEINVADERS_VECTOR_H
#define SPACEINVADERS_VECTOR_H

namespace utils {
	/**
	 * custom vector class to not be dependent on SFML vector classes
	 */
	struct Vector {
		float x;
		float y;

		/**
		 * default constructor
		 */
		Vector();

		/**
		 * parametrized constructor
		 * @param x float
		 * @param y float
		 */
		Vector(float x, float y);

		/**
		 * convert to bool
		 * @return true if not (0, 0)
		 */
		explicit operator bool();

		/**
		 * get Euclidian length
		 */
		[[nodiscard]] float length() const;

		/**
		 * normalize
		 * @return normalized vector
		 */
		[[nodiscard]] Vector normalize() const;

		/**
		 * rotate vector by an angle
		 * @param angle in degrees
		 * @return rotated vector
		 */
		[[nodiscard]] [[maybe_unused]] Vector rotate(float angle) const;

		/**
		 * calculate the dot product
		 * @param vector second operand
		 * @return float
		 */
		[[nodiscard]] [[maybe_unused]] float dot(Vector vector) const;

		/**
		 * negation
		 * @return negative
		 */
		Vector operator-() const;

		/**
		 * addition
		 * @param vector operand
		 * @return reference to this
		 */
		Vector& operator+=(Vector vector);

		/**
		 * subtraction
		 * @param vector operand
		 * @return reference to this
		 */
		Vector& operator-=(Vector vector);

		/**
		 * multiplication
		 * @param amount operand
		 * @return reference to this
		 */
		Vector& operator*=(float amount);

		/**
		 * division
		 * @param amount operand
		 * @return reference to this
		 */
		Vector& operator/=(float amount);

		/**
		 * addition
		 * @param vector operand
		 * @return sum
		 */
		Vector operator+(Vector vector) const;

		/**
		 * subtraction
		 * @param vector operand
		 * @return difference
		 */
		Vector operator-(Vector vector) const;

		/**
		 * division
		 * @param vector operand
		 * @return quotient
		 */
		Vector operator/(Vector vector) const;

		/**
		 * multiplication
		 * @param vector operand
		 * @return product
		 */
		Vector operator*(Vector vector) const;

		/**
		 * multiplication
		 * @param amount operand
		 * @return product
		 */
		Vector operator*(float amount) const;

		/**
		 * division
		 * @param amount operand
		 * @return quotient
		 */
		Vector operator/(float amount) const;

		/**
		 * addition
		 * @param amount operand
		 * @return sum
		 */
		Vector operator+(float amount) const;
	};

	/**
	 * determine sign of float
	 * @return -1 if negative, 1 if positive
	 */
	float getSign(float);

	/**
	 * modulo that always returns a positive value
	 * @param value	left value
	 * @param m right value
	 * @return positive modulo
	 */
	int positiveModulo(int value, int m);
}


#endif //SPACEINVADERS_VECTOR_H
