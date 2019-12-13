//
// Created by ward on 11/19/19.
//

#include "entity.h"

SI::model::Entity::Entity() : mustDelete(false) {}

std::vector <std::shared_ptr<SI::model::Entity>> SI::model::Entity::getNewModels() {
	auto copy = newModels;
	newModels.clear();
	return copy;
}

bool SI::model::Entity::mayDeleteThis() const {
	return mustDelete;
}

void SI::model::Entity::addModel(const std::shared_ptr <Entity>& model) {
	newModels.emplace_back(model);
}

void SI::model::Entity::addModels(const std::vector<std::shared_ptr<Entity>>& models) {
	newModels.insert(newModels.end(), models.begin(), models.end());
}

void SI::model::Entity::deleteThis() {
	mustDelete = true;
	notifyObservers();
}
