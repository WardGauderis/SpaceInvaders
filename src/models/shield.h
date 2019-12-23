//
// Created by ward on 12/15/19.
//

#ifndef SPACEINVADERS_SHIELDMODEL_H
#define SPACEINVADERS_SHIELDMODEL_H

#include "physicalEntity.h"

namespace SI::model {

	class Shield : public PhysicalEntity {
	public:

		struct ShieldSegment {
			constexpr static int amount = 15;
			std::array<std::array<bool, amount>, amount> points{};

			enum class Type {
				full,
				rightBottom,
				leftBottom,
				rightTop,
				leftTop
			};

			ShieldSegment() = default;

			explicit ShieldSegment(Type type);

			static const utils::Vector& size();
		};

		explicit Shield(const utils::Vector& position);

		bool collidesWith(const std::shared_ptr<PhysicalEntity>& entity) final;

		[[nodiscard]] const std::array<std::array<ShieldSegment, 3>, 4>& getSegments() const;

		[[nodiscard]] utils::Vector convert(int x0, int y0, int x1, int y1) const;

		~Shield() final = default;

	private:
		std::array<std::array<ShieldSegment, 3>, 4> segments{};

		bool collidesWithSegment(int x0, int y0, const std::shared_ptr<PhysicalEntity>& entity);

		void onCollisionExplosion(int x0, int y0, int x1, int y1, const std::shared_ptr<PhysicalEntity>& entity);

		static bool correct(int& x0, int& y0, int& x1, int& y1);
	};

}

#endif //SPACEINVADERS_SHIELDMODEL_H
