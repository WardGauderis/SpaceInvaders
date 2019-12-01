//
// Created by ward on 11/28/19.
//

#ifndef SPACEINVADERS_TRANSFORMATION_H
#define SPACEINVADERS_TRANSFORMATION_H

namespace utils {

	class Transformation {
	public:
		/**
		 * Meyer's singleton pattern constructor
		 * @return the singleton transformation
		 */
		static Transformation& get();

		Transformation(const Transformation&) = delete;

		Transformation& operator=(const Transformation&) = delete;

		/**
		 * Set pixel resolution
		 * @param x in pixels
		 * @param y in pixels
		 */
		void setDimensions(unsigned int x, unsigned int y);

		/**
		 * convert from range [-4, 4] to [0, width]
		 * @param x width
		 * @return width
		 */
		unsigned int convertWidth(float x);

		/**
		 * convert from range [-3, 3] to [0, height]
		 * @param y height
		 * @return height
		 */
		unsigned int convertHeight(float y);

		/**
		 * convert from range [0, width] to [-4, 4]
		 * @param x width
		 * @return width
		 */
		float convertWidth(unsigned int x);

		/**
		 * convert from range [0, height] to [-3, 3]
		 * @param y height
		 * @return height
		 */
		float convertHeight(unsigned int y);

	private:
		unsigned int width;
		unsigned int height;

		Transformation() = default;

		~Transformation() = default;
	};

}

#endif //SPACEINVADERS_TRANSFORMATION_H
