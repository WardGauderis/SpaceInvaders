#include "spaceInvaders.h"
#include "utils/stopWatch.h"

int main() {
	utils::StopWatch::get().printFPS(true);
	SI::SpaceInvaders spaceInvaders;
	spaceInvaders.eventLoop();
	return 0;
}