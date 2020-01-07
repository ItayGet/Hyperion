#include "hpr.h"
#include <iostream>

namespace Hpr = Hyperion;

int main(void) {
	bool succ = false;
	Hpr::Hyperion a("Test", 640, 480, succ);

	if (succ) {
		a.addShape(
			{
				{ 1., 0., -5. },
				.25,
				{ .1, .5, 0. },
				Hpr::ShapeType::Sphere
			}
		);
		a.addShape(
			{
				{ .5, 0., -5. },
				.25,
				{ 1., 0., 1. },
				Hpr::ShapeType::Square
			}
		);		
		a.addShape(
			{
				{ 0., 0., -5. },
				.25,
				{ 0., .5, 1. },
				Hpr::ShapeType::Sphere
			}
		);

		while (a.update()) {
		}
	}
	a.terminate();
}