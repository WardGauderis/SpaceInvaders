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

		[[nodiscard]] bool getTeam() const;

		~PhysicalEntity() override = default;

		virtual bool collidesWith(const std::shared_ptr<PhysicalEntity>& entity);

		static bool
		AABB(utils::Vector p0, utils::Vector s0, utils::Vector p1, utils::Vector s1);

		virtual void onCollision(const std::shared_ptr<PhysicalEntity>& entity);

		void deleteThis() override;

	protected:
		float drag;
		utils::Vector size;
		utils::Vector position;
		utils::Vector velocity;

		bool team;

		virtual void move();

		[[nodiscard]] utils::Vector detectWallCollision() const;

		virtual void onWallCollision(utils::Vector wall);

	};

}

#endif //SPACEINVADERS_PHYSICALENTITYMODEL_H
