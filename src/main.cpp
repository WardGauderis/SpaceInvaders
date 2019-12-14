#include <iostream>

#include "spaceInvaders.h"
#include "utils/stopWatch.h"
#include "utils/transformation.h"

int main() {
	utils::StopWatch::get().printFPS(true);
	utils::Transformation::get().setDimensions(1200, 900);

	try {
		SI::SpaceInvaders spaceInvaders;
		spaceInvaders.eventLoop();
	} catch (const std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}
	return 0;
}