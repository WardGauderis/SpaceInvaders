//
// Created by ward on 12/15/19.
//

#ifndef SPACEINVADERS_SHIELDMODEL_H
#define SPACEINVADERS_SHIELDMODEL_H

#include "physicalEntity.h"

namespace SI::model {
	/**
	 * model class for the shields
	 */
	class Shield : public PhysicalEntity {
	public:
		/**
		 * a segment of the shield
		 * multiple segments result in faster collision detection by Grid based space partitioning
		 */
		struct ShieldSegment {
			constexpr static int amount = 15;
			std::array<std::array<bool, amount>, amount> points{};
			/**
			 * types of shield segments
			 */
			enum class Type {
				full,
				rightBottom,
				leftBottom,
				rightTop,
				leftTop
			};

			ShieldSegment() = default;

			/**
			 * construct a shield segment of a certain type
			 * @param type enum
			 */
			explicit ShieldSegment(Type type);

			/**
			 * get the size of a shield segment in an exception safe way
			 * @return size
			 */
			static const utils::Vector& size();
		};

		/**
		 * construct a shield around a position
		 * @param position vector
		 */
		explicit Shield(const utils::Vector& position);

		/**
		 * check if an entity collides with the shield
		 * @param entity entity
		 * @return true if it collides
		 */
		bool collidesWith(const std::shared_ptr<PhysicalEntity>& entity) final;

		/**
		 * get the different segments of a shield
		 * @return array of segments
		 */
		[[nodiscard]] const std::array<std::array<ShieldSegment, 3>, 4>& getSegments() const;

		/**
		 * convert indices to vector
		 * @param x0 x in shield
		 * @param y0 y in shield
		 * @param x1 x in segment
		 * @param y1 y in segment
		 * @return vector
		 */
		[[nodiscard]] utils::Vector convert(int x0, int y0, int x1, int y1) const;

		~Shield() final = default;

	private:
		std::array<std::array<ShieldSegment, 3>, 4> segments{};

		/**
		 * checks if an entity collides with a segment
		 * by doing collision checks at 3 different levels, the operation becomes much less heavy (Grid based space partitioning)
		 * @param x0 x in shield
		 * @param y0 y in shield
		 * @param entity entity
		 * @return true if it collides
		 */
		bool collidesWithSegment(int x0, int y0, const std::shared_ptr<PhysicalEntity>& entity);

		/**
		 * create an explosion and deteriorate the shield on impact
		 * @param x0 x in shield
		 * @param y0 y in shield
		 * @param x1 x in segment
		 * @param y1 y in segment
		 * @param entity entity
		 */
		void onCollisionExplosion(int x0, int y0, int x1, int y1, const std::shared_ptr<PhysicalEntity>& entity);

		/**
		 * correct the indices if they go out of bounds
		 * @param x0 x in shield
		 * @param y0 y in shield
		 * @param x1 x in segment
		 * @param y1 y in segment
		 * @return true if the resulting indices are correctly fixed
		 */
		static bool correct(int& x0, int& y0, int& x1, int& y1);
	};

}

#endif //SPACEINVADERS_SHIELDMODEL_H
