#include "hpr.h"

int main(void) {
	bool succ = false;
	Hyperion::Hyperion a("Test", 640, 480, succ);

	if (succ) {
		while (a.Update());
	}
	a.terminate();
}