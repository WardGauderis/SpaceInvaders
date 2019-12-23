//
// Created by ward on 12/8/19.
//

#ifndef SPACEINVADERS_PHYSICALENTITYMODEL_H
#define SPACEINVADERS_PHYSICALENTITYMODEL_H

#include "entity.h"
#include "../utils/vector.h"

namespace SI::model {
	/**
	 * model for physical entities
	 */
	class PhysicalEntity : public Entity {
	public:
		/**
		 * construct with attributes
		 * @param drag 'air' resistance
		 * @param size vector
		 * @param position vector
		 * @param velocity vector
		 * @param team true if friendly
		 */
		PhysicalEntity(float drag, const utils::Vector& size, const utils::Vector& position,
		               const utils::Vector& velocity, bool team);

		/**
		 * function that is called when the model is update
		 * move the physical object
		 */
		void update() override;

		/**
		 * adjust velocity
		 * @param vel adjust vector
		 */
		void addVelocity(const utils::Vector& vel);

		/**
		 * get the position
		 * @return position
		 */
		[[nodiscard]] const utils::Vector& getPosition() const;

		/**
		 * set the position
		 * @param position vector
		 */
		void setPosition(const utils::Vector& position);

		/**
		 * get the velocity
		 * @return velocity
		 */
		[[nodiscard]] const utils::Vector& getVelocity() const;

		/**
		 * set the velocity
		 * @param velocity vector
		 */
		void setVelocity(const utils::Vector& velocity);

		/**
		 * get the size
		 * @return size
		 */
		[[nodiscard]] const utils::Vector& getSize() const;

		/**
		 * set the size
		 * @param size vector
		 */
		void setSize(const utils::Vector& size);

		/**
		 * get the team
		 * @return true if friendly
		 */
		[[nodiscard]] bool getTeam() const;

		/**
		 * check whether the entity collides with this, according to this
		 * @param entity other entity
		 * @return true if it collides
		 */
		virtual bool collidesWith(const std::shared_ptr<PhysicalEntity>& entity);

		/**
		 * axis aligned bounding boxes collision detection
		 * @param p0 postion a
		 * @param s0 size a
		 * @param p1 potition b
		 * @param s1 size b
		 * @return true if the boxes collide
		 */
		static bool
		AABB(utils::Vector p0, utils::Vector s0, utils::Vector p1, utils::Vector s1);

		/**
		 * function is executed if both entities collide
		 * @param entity other entity
		 */
		virtual void onCollision(const std::shared_ptr<PhysicalEntity>& entity);

		/**
		 * indicate that this may be deleted
		 */
		void deleteThis() override;

		~PhysicalEntity() override = default;

	protected:
		float drag;
		utils::Vector size;
		utils::Vector position;
		utils::Vector velocity;

		bool team;

		/**
		 * move this
		 */
		virtual void move();

		/**
		 * check whether this collides with the walls of the window
		 * @return vector with the collision position
		 */
		[[nodiscard]] utils::Vector detectWallCollision() const;

		/**
		 * handle wall collision
		 * @param wall collision position
		 */
		virtual void onWallCollision(utils::Vector wall);

	};

}

#endif //SPACEINVADERS_PHYSICALENTITYMODEL_H
