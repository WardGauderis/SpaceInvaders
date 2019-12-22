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
			const static utils::Vector size;

			std::array<std::array<bool, amount>, amount> points{};

			enum class Type {
				full,
				rightbottom,
				leftbottom,
				righttop,
				lefttop
			};

			ShieldSegment() = default;

			explicit ShieldSegment(Type type);
		};

		explicit Shield(const utils::Vector& position);

		bool collidesWith(const std::shared_ptr<PhysicalEntity>& entity) final;

		[[nodiscard]] const std::array<std::array<ShieldSegment, 3>, 4>& getSegments() const;

		utils::Vector convert(size_t x0, size_t y0, size_t x1, size_t y1) const;

		~Shield() final = default;

	private:
		std::array<std::array<ShieldSegment, 3>, 4> segments{};

		bool collidesWithSegment(int x0, int y0, const std::shared_ptr<PhysicalEntity>& entity);

		void onCollision(int x0, int y0, int x1, int y1, const std::shared_ptr<PhysicalEntity>& entity);

		static bool correct(int& x0, int& y0, int& x1, int& y1) ;
	};

}

#endif //SPACEINVADERS_SHIELDMODEL_H
