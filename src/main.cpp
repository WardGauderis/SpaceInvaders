#include <iostream>
#include "utils/stopWatch.h"
#include <timer>
#include <thread>

int main() {
	StopWatch::instance().setTimeOut(1000ms);
	for (int i = 0; i < 60; ++i) {
		Timer t;
		if (i % 3 == 0) std::this_thread::sleep_for(500ms);
		if(i == 5) StopWatch::instance().setTimeOut(200ms);
		StopWatch::instance().sleepUntilTime();
		std::cout << i << std::endl;
	}
	return 0;
}