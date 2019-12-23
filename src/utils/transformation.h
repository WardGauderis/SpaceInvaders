//
// Created by ward on 11/28/19.
//

#ifndef SPACEINVADERS_TRANSFORMATION_H
#define SPACEINVADERS_TRANSFORMATION_H

#include "vector.h"
#include <SFML/Graphics.hpp>

namespace utils {

	/**
	 * class that convert float values from [-4, 4] by [-3, 3] to a custom pixel range for display (singleton)
	 */
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
		 * get the set width
		 * @return width
		 */
		[[nodiscard]] unsigned int getWidth() const;

		/**
		 * get the set height
		 * @return height
		 */
		[[nodiscard]] unsigned int getHeight() const;

		/**
		 * convert point from range [-4, 4], [-3, 3] to [0, width], [0, height]
		 * @param vector vector from model
		 * @return vector from view (float, unsigned int or int)
		 */
		template<typename T>
		[[nodiscard]] sf::Vector2<T> convertPoint(Vector vector) const;

		/**
		 * convert distance from range [-4, 4], [-3, 3] to [0, width], [0, height]
		 * @param vector vector from model
		 * @return vector from view (float, unsigned int or int)
		 */
		template<typename T>
		[[nodiscard]] sf::Vector2<T> convertDistance(Vector vector) const;

	private:
		unsigned int width;
		unsigned int height;

		Transformation() = default;

		~Transformation() = default;

		/**
 		* convert from range [-4, 4] to [0, width]
 		* @param x width
 		* @return width (float, unsigned int or int)
 		*/
		template<typename T>
		[[nodiscard]] T convertWidth(float x) const;

		/**
		 * convert from range [-3, 3] to [0, height]
		 * @param y height
		 * @return height (float, unsigned int or int)
		 */
		template<typename T>
		[[nodiscard]] T convertHeight(float y) const;
	};

}

#endif //SPACEINVADERS_TRANSFORMATION_H
