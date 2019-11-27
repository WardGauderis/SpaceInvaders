//
// Created by ward on 11/27/19.
//

#include "stopWatch.h"
#include <thread>

StopWatch& StopWatch::instance() {
	static StopWatch stopWatch;
	return stopWatch;
}

void StopWatch::setTimeOut(std::chrono::milliseconds timeOut) {
	StopWatch::delta = timeOut;
	start = std::chrono::steady_clock::now();
}

void StopWatch::sleepUntilTime() {
	std::this_thread::sleep_until(start + delta);
	start = std::chrono::steady_clock::now();
}