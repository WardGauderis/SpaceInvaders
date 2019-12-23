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


utils::Timer::Timer(const unsigned int coolDown) : coolDown(coolDown), time(0), active(true) {}

void utils::Timer::update() {
	if(!active) return;
	if (time != 0) --time;
}

bool utils::Timer::ready() {
	if (time == 0) {
		if(active) reset();
		return true;
	}
	return false;
}

void utils::Timer::reset() {
	time = coolDown;
}

void utils::Timer::stop() {
	active = false;
}

void utils::Timer::start() {
	active = true;
}

void utils::Timer::setTime(unsigned int newTime) {
	Timer::time = newTime;
}

unsigned int utils::Timer::getCooldown() const {
	return coolDown;
}

unsigned int utils::Timer::getTime() const {
	return time;
}
