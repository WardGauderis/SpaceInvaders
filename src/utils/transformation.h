//
// Created by ward on 11/28/19.
//

#ifndef SPACEINVADERS_TRANSFORMATION_H
#define SPACEINVADERS_TRANSFORMATION_H

#include "vector.h"
#include <SFML/Graphics.hpp>

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

		[[nodiscard]] unsigned int getWidth() const;

		[[nodiscard]] unsigned int getHeight() const;

		/**
		 * convert point from range [-4, 4], [-3, 3] to [0, width], [0, height]
		 * @param vector vector from model
		 * @return vector from view
		 */
		template<typename T>
		[[nodiscard]] sf::Vector2<T> convertPoint(Vector vector) const;

		/**
		 * convert distance from range [-4, 4], [-3, 3] to [0, width], [0, height]
		 * @param vector vector from model
		 * @return vector from view
		 */
		template<typename T>
		[[nodiscard]] sf::Vector2<T> convertDistance(Vector vector) const;

		/**
		 * convert from range [0, width], [0, height] to [-4, 4], [-3, 3]
		 * @param vector vector from view
		 * @return vector from model
		 */
//		[[nodiscard]] Vector convert(sf::Vector2i vector) const;

	private:
		unsigned int width;
		unsigned int height;

		Transformation() = default;

		~Transformation() = default;

		/**
 		* convert from range [-4, 4] to [0, width]
 		* @param x width
 		* @return width
 		*/
		template<typename T>
		[[nodiscard]] T convertWidth(float x) const;

		/**
		 * convert from range [-3, 3] to [0, height]
		 * @param y height
		 * @return height
		 */
		template<typename T>
		[[nodiscard]] T convertHeight(float y) const;

		/**
		 * convert from range [0, width] to [-4, 4]
		 * @param x width
		 * @return width
		 */
//		[[nodiscard]] float convertWidth(int x) const;

		/**
		 * convert from range [0, height] to [-3, 3]
		 * @param y height
		 * @return height
		 */
//		[[nodiscard]] float convertHeight(int y) const;
	};

}

#endif //SPACEINVADERS_TRANSFORMATION_H
