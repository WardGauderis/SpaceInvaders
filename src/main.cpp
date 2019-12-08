#include "spaceInvaders.h"
#include "utils/stopWatch.h"
#include "utils/transformation.h"

int main() {
	utils::StopWatch::get().printFPS(true);
	utils::Transformation::get().setDimensions(1200, 900);
	SI::SpaceInvaders spaceInvaders;
	spaceInvaders.eventLoop();
	return 0;
}