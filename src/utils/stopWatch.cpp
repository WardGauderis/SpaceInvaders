//
// Created by ward on 11/27/19.
//

#include <thread>
#include <iostream>

#include "stopWatch.h"

utils::StopWatch& utils::StopWatch::get() {
	static StopWatch stopWatch;
	return stopWatch;
}

bool utils::StopWatch::updateModel() {
	bool update = updateTimer >= frameTime;
	if (update) {
		updateTimer -= frameTime;
		shouldUpdateView = true;
	}
	return update;
}

bool utils::StopWatch::updateView() {
	auto currentTime = std::chrono::steady_clock::now();
	auto passedTime = currentTime - lastTime;
	lastTime = currentTime;

	updateTimer += passedTime;
	fpsTimeCounter += passedTime;

	if (fpsTimeCounter >= 1s) {
		if (showFPS) {
			auto msPerFrame = 1000.0 / fps;
			std::cout << msPerFrame << " ms " << fps << " fps" << std::endl;
		}
		fpsTimeCounter = 0ns;
		fps = 0;
	}

	if (shouldUpdateView) ++fps;
	else std::this_thread::sleep_for(1ms);

	bool update = shouldUpdateView;
	shouldUpdateView = false;
	return update;
}

void utils::StopWatch::setFPS(unsigned int newFPS) {
	frameTime = 1.0s / newFPS;
}

void utils::StopWatch::printFPS(bool print) {
	showFPS = print;
}
