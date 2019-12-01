//
// Created by ward on 11/27/19.
//

#ifndef SPACEINVADERS_STOPWATCH_H
#define SPACEINVADERS_STOPWATCH_H

#include <chrono>

using namespace std::chrono_literals;

namespace utils {

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
		bool renderView();

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

}

#endif //SPACEINVADERS_STOPWATCH_H
