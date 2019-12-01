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

		bool updateModel();

		bool updateView();

		void setFPS(unsigned int fps);

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
