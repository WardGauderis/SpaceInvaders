//
// Created by ward on 12/1/19.
//

#include "observer.h"
#include <algorithm>

void utils::Subject::addObserver(const std::shared_ptr<Observer>& observer) {
	observers.emplace_back(observer);
}

void utils::Subject::removeObserver(const std::shared_ptr<Observer>& observer) {
	observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void utils::Subject::notifyObservers() {
	for (const auto& observer: observers) {
		observer->notify();
	}
}

const std::vector<std::shared_ptr<utils::Observer>>& utils::Subject::getObservers() const {
	return observers;
}

void utils::Subject::setObservers(const std::vector<std::shared_ptr<Observer>>& observers) {
	Subject::observers = observers;
}
