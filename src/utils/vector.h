//
// Created by ward on 12/2/19.
//

#ifndef SPACEINVADERS_VECTOR_H
#define SPACEINVADERS_VECTOR_H

namespace utils {

	struct Vector {
		float x;
		float y;

		Vector& operator+=(const Vector& vector);
	};

}


#endif //SPACEINVADERS_VECTOR_H
