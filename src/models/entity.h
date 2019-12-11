//
// Created by ward on 11/19/19.
//

#ifndef SPACEINVADERS_ENTITYMODEL_H
#define SPACEINVADERS_ENTITYMODEL_H

#include "../utils/observer.h"

namespace SI::model {

	class Entity : public utils::Subject {
	public:
		Entity();

		virtual void update() = 0;

		virtual std::vector<std::shared_ptr<Entity>> getNewModels();

		[[nodiscard]] bool mayDeleteThis() const;

		virtual ~Entity() = default;

	protected:
		void addModel(const std::shared_ptr<Entity>& model);

		void addModels(const std::vector<std::shared_ptr<Entity>>& models);

		void deleteThis();

	private:
		std::vector<std::shared_ptr<Entity>> newModels;
		bool mustDelete;
	};

}

#endif //SPACEINVADERS_ENTITYMODEL_H
