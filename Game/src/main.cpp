#include "hpr.h"
#include "glm/gtx/transform.hpp"

namespace Hpr = Hyperion;

int main(void) {
	bool succ = false;
	Hpr::Hyperion a("Test", 640, 480, succ);

	glm::mat4 trans = glm::mat4(1.);
	trans = glm::rotate(trans, glm::radians(40.f), glm::vec3(0., 1., 1.));
	trans = glm::translate(trans, glm::vec3(0., 0., 10.));

	if (succ) {
		auto go = a.addShape();
		go.setType(Hpr::ShapeType::Square);
		go.setColor(glm::vec3(1., 0., 0.));
		go.setRadius(1.);
		go.setTranform(trans);

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

		int i = 0;
		while (a.update()) {
			i++;
			if (i < 20) { continue; }
			go.translate(glm::vec3(0., 0., -.05));
		}
	}
	a.terminate();
}