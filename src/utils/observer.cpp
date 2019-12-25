//
// Created by ward on 12/1/19.
//

#include <algorithm>

#include "observer.h"

void utils::Subject::addObserver(const std::weak_ptr<Observer>& observer)
{
        if (!observer.lock())
                return;
        observers.emplace_back(observer);
}

void utils::Subject::removeObserver(const std::weak_ptr<Observer>& observer)
{
        observers.erase(
            std::remove_if(observers.begin(), observers.end(),
                           [&observer](const std::weak_ptr<Observer>& obs) { return obs.lock() == observer.lock(); }),
            observers.end());
}

void utils::Subject::notifyObservers()
{
        for (const auto& observer : observers) {
                if (auto lock = observer.lock())
                        lock->notify();
        }
}

const std::vector<std::weak_ptr<utils::Observer>>& utils::Subject::getObservers() const { return observers; }

void utils::Subject::setObservers(const std::vector<std::weak_ptr<Observer>>& newObservers)
{
        Subject::observers = newObservers;
}
