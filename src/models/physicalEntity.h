//
// Created by ward on 12/8/19.
//

#ifndef SPACEINVADERS_PHYSICALENTITYMODEL_H
#define SPACEINVADERS_PHYSICALENTITYMODEL_H

#include "entity.h"
#include "../utils/vector.h"

namespace SI::model {

	class PhysicalEntity : public Entity {
	public:

		PhysicalEntity(float drag, const utils::Vector& size, const utils::Vector& position,
		               const utils::Vector& velocity, bool team);

		void update() override;

		void addVelocity(const utils::Vector& vel);

		[[nodiscard]] const utils::Vector& getPosition() const;

		void setPosition(const utils::Vector& position);

		[[nodiscard]] const utils::Vector& getVelocity() const;

		void setVelocity(const utils::Vector& velocity);

		[[nodiscard]] const utils::Vector& getSize() const;

		void setSize(const utils::Vector& size);

		bool getTeam() const;

		~PhysicalEntity() override = default;

		virtual bool collidesWith(const std::shared_ptr<PhysicalEntity>& entity);

		static bool
		AABB(const utils::Vector p0, const utils::Vector s0, const utils::Vector p1, const utils::Vector s1);

		virtual void onCollision(const std::shared_ptr<PhysicalEntity>& entity);

	protected:
		float drag;
		utils::Vector size;
		utils::Vector position;
		utils::Vector velocity;

		bool team;

		virtual void move();

		[[nodiscard]] utils::Vector detectWallCollision() const;

		virtual void onWallCollision(utils::Vector wall);

		void deleteThis() override;

	};

}

#endif //SPACEINVADERS_PHYSICALENTITYMODEL_H
