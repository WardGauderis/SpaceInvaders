//
// Created by ward on 11/27/19.
//

#ifndef SPACEINVADERS_STOPWATCH_H
#define SPACEINVADERS_STOPWATCH_H

#include <chrono>

using namespace std::chrono_literals;

namespace utils {
	/**
	 * stopwatch class that determines when the model (and controller) or the view should update
	 * for a constant game speed (singleton)
	 */
	class StopWatch {
	public:
		/**
		 * Meyer's singleton pattern constructor
		 * @return the singleton stopwatch
		 */
		static StopWatch& get();

		StopWatch(const StopWatch&) = delete;

		StopWatch& operator=(const StopWatch&) = delete;

		/**
		 * tries to be ran at the set fps at the cost of the frequency of updateView()
		 * @return whether the model must be updated
		 */
		bool updateModel();

		/**
		 * tries to be ran at the set fps but updateModel() has priority;
		 * also prints the fps if requested
		 * @return whether the view must be rendered
		 */
		bool updateView();

		/**
		 * set fps
		 * @param newFPS preferred fps
		 */
		void setFPS(unsigned int newFPS);

		/**
		 * set whether the fps must be printed
		 * @param print bool
		 */
		void printFPS(bool print);


	private:
		unsigned int fps = 0;
		std::chrono::nanoseconds fpsTimeCounter = 0ns;
		std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds> lastTime = std::chrono::steady_clock::now();

		std::chrono::duration<long double> updateTimer = 1.0s;
		std::chrono::duration<long double> frameTime = 1.0s / 60.0;

		bool shouldUpdateView = false;
		bool showFPS = false;

		StopWatch() = default;

		~StopWatch() = default;

	};

	/**
	 * class that counts down to zero each time it is updated
	 * designed to work with game-ticks (not real time)
	 */
	class Timer {
	public:
		/**
		 * construct the timer and set its cooldown
		 * @param coolDown amount of ticks
		 */
		explicit Timer(unsigned int coolDown);

		/**
		 * count down if the the timer is active
		 */
		void update();

		/**
		 * resets the timer if it has reached zero
		 * @return tue if the timer is done
		 */
		bool ready();

		/**
		 * resets the timer
		 */
		void reset();

		/**
		 * stops the timer
		 */
		void stop();

		/**
		 * starts the timer
		 */
		void start();

		/**
		 * set the current time
		 * @param time amount of ticks
		 */
		void setTime(unsigned int time);

		/**
		 * get the cooldown
		 * @return the set cooldown
		 */
		[[nodiscard]] unsigned int getCooldown() const;

		/**
		 * get the current time
		 * @return current amount of ticks
		 */
		[[nodiscard]] unsigned int getTime() const;

	private:
		unsigned int coolDown;
		unsigned int time;
		bool active;
	};

}

#endif //SPACEINVADERS_STOPWATCH_H
