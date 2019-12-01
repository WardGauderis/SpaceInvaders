#include "utils/stopWatch.h"
#include <thread>

int main() {
	utils::StopWatch::get().printFPS(true);
	bool ja = true;
	while (ja) {
		while (utils::StopWatch::get().updateModel()) {
			std::this_thread::sleep_for(2ms);
		}
		if (utils::StopWatch::get().updateView()) {
			std::this_thread::sleep_for(20ms);
		}
	}
	return 0;
}