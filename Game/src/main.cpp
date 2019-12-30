#include "hpr.h"
#include <iostream>

int main(void) {
	bool succ = false;
	Hyperion::Hyperion a("Test", 640, 480, succ);

	if (succ) {
		a.addShape(
			{
				{ 1., 0., -5. },
				.25,
				{.75, .75, .75}
			}
		);
		a.addShape(
			{
				{ .5, 0., -5. },
				.25,
				{.75, .75, .75}
			}
		);		
		a.addShape(
			{
				{ 0., 0., -5. },
				.25,
				{.5, .5, .5}
			}
		);

		while (a.update()) {
		}
	}
	a.terminate();
}