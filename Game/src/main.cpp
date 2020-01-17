#include "hpr.h"
#include <glm/gtc/matrix_transform.hpp>

namespace Hpr = Hyperion;

int main(void) {
	bool succ = false;
	Hpr::Hyperion a("Test", 640, 480, succ);

	glm::mat4 trans = glm::rotate(glm::mat4(1.), glm::radians(40.f), glm::vec3(0., 1., 1.));
	trans = glm::translate(trans, glm::vec3(0., 0., 5.));

	if (succ) {
		a.addShape(
			{
				trans,
				{ 1., 0., 0., 1. },
				.25,
				Hpr::ShapeType::Square
			}
		);
		//a.addShape(
		//	{
		//		{ .5, 0., -5. },
		//		.25,
		//		{ 1., 0., 1. },
		//		Hpr::ShapeType::Square
		//	}
		//);		
		//a.addShape(
		//	{
		//		{ 0., 0., -5. },
		//		.25,
		//		{ 0., .5, 1. },
		//		Hpr::ShapeType::Sphere
		//	}
		//);

		while (a.update()) {
		}
	}
	a.terminate();
}