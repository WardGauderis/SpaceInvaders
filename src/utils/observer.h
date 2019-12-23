//
// Created by ward on 12/1/19.
//

#ifndef SPACEINVADERS_OBSERVER_H
#define SPACEINVADERS_OBSERVER_H

#include <memory>

namespace utils {
	/**
	 * abstract observer class from which observers must inherit
	 */
	class Observer {
	public:
		/**
		 * function that is ran on update
		 */
		virtual void notify() = 0;

		virtual ~Observer() = default;
	};

	/**
	 * subject class from which subject must inherit
	 */
	class Subject {
	public:
		/**
		 * add an observer to the subject
		 * @param observer new observer
		 */
		void addObserver(const std::shared_ptr<Observer>& observer);

		/**
		 * remove a certain observer from the subject;
		 * @param observer observer to remove
		 */
		void removeObserver(const std::shared_ptr<Observer>& observer);

		/**
		 * get a vector of all the observers of the subject
		 * @return vector
		 */
		[[nodiscard]] const std::vector<std::shared_ptr<Observer>>& getObservers() const;

		/**
		 * replace the current observers with new ones
		 * @param observers vector of new observers
		 */
		void setObservers(const std::vector<std::shared_ptr<Observer>>& observers);

	protected:
		/**
		 * notify all observers
 		 */
		void notifyObservers();

	private:
		std::vector<std::shared_ptr<Observer>> observers;

	};

}

#endif //SPACEINVADERS_OBSERVER_H
