#include "spaceInvaders.h"
#include "utils/stopWatch.h"
#include "utils/transformation.h"

int main() {
	utils::StopWatch::get().printFPS(true);
	utils::Transformation::get().setDimensions(800, 600);
	SI::SpaceInvaders spaceInvaders;
	spaceInvaders.eventLoop();
	return 0;
}