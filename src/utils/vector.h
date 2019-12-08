//
// Created by ward on 12/2/19.
//

#ifndef SPACEINVADERS_VECTOR_H
#define SPACEINVADERS_VECTOR_H

namespace utils {

	struct Vector {
		float x;
		float y;

		[[nodiscard]] float length() const;

		Vector& operator+=(Vector vector);

		Vector& operator*=(float amount);

		Vector operator+(Vector vector) const;

		Vector operator-(Vector vector) const;

		Vector operator/(float amount) const;
	};

}


#endif //SPACEINVADERS_VECTOR_H
