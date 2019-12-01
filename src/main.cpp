#include "utils/stopWatch.h"
#include <thread>
#include <iostream>

int main() {
	utils::StopWatch::get().printFPS(true);
	bool ja = true;
	while (ja) {
		while (utils::StopWatch::get().updateModel()) {
		}
		if (utils::StopWatch::get().renderView()) {
		}
	}
	return 0;
}