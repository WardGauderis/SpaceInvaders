//
// Created by ward on 12/24/19.
//

#ifndef SPACEINVADERS_SPYMODEL_H
#define SPACEINVADERS_SPYMODEL_H

#include "../enemy.h"
#include "../../utils/stopWatch.h"


namespace SI::model {
	/**
	 * model class for the type of enemy spy
	 */
	class Spy : public Enemy {
	public:
		/**
		 * default constructor
		 */
		Spy();

		/**
		 * function that is called when the model is updated
		 * update the position and state
		 */
		void update() final;

		/**
		 * handle collision
		 * only collide with bullets if visible
		 * @param entity entity to check
		 * @return true if it collides
		 */
		bool collidesWith(const std::shared_ptr<PhysicalEntity>& entity) final;

		/**
		 * try to shoot a bullet
		 * only possible if visible
		 * @return success
		 */
		bool shoot() final;

		/**
		 * get the opacity of the spy
		 * @return uint8_t
		 */
		[[nodiscard]] uint8_t getOpacity() const;

		~Spy() final = default;

	private:
		/**
		 * state of spy
		 */
		enum class Visibility {
			visible,
			invisible,
			appearing,
			disappearing
		};


		Visibility state;
		utils::Timer timer;
		static const unsigned int stable = 120;
		static const unsigned int transition = 45;
	};

}

#endif //SPACEINVADERS_SPYMODEL_H
