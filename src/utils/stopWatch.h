//
// Created by ward on 11/27/19.
//

#ifndef SPACEINVADERS_STOPWATCH_H
#define SPACEINVADERS_STOPWATCH_H

#include <chrono>

using namespace std::chrono_literals;

class StopWatch {
public:
	/**
	 * Meyer's singleton pattern constructor
	 * @return the singleton stopwatch
	 */
	static StopWatch& instance();

	StopWatch(const StopWatch&) = delete;

	StopWatch& operator=(const StopWatch&) = delete;

	/**
	 * Set the duration of one cycle
	 * @param timeOut duration in milliseconds
	 */
	void setTimeOut(std::chrono::milliseconds timeOut);

	/**
	 * Sleep until the next cycle is done
	 */
	void sleepUntilTime();

private:
	std::chrono::milliseconds delta{};
	std::chrono::time_point<std::chrono::steady_clock> start{};

	StopWatch() = default;

	~StopWatch() = default;

};

#endif //SPACEINVADERS_STOPWATCH_H
