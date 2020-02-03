#include "hpr.h"
#include "glm/gtx/transform.hpp"

#include "glm/gtx/string_cast.hpp"
#include <iostream>

namespace Hpr = Hyperion;

int main(void) {
	bool succ = false;
	Hpr::Hyperion a("Test", 640, 480, succ);

	glm::mat4 trans = glm::mat4(1.);
	trans = glm::rotate(trans, glm::radians(40.f), glm::vec3(0., 0., 1.));
	trans = glm::translate(trans, glm::vec3(0., 0., 10.));



	if (succ) {
		auto go = a.addShape();
		go.setType(Hpr::ShapeType::Square);
		go.setColor(glm::vec3(1., 0., 0.));
		go.setRadius(.5);
		go.setTranform(trans);

		trans = glm::translate(trans, glm::vec3(1., 0., 0.));

		auto go1 = a.addShape();
		go1.setType(Hpr::ShapeType::Square);
		go1.setColor(glm::vec3(1., 0., 0.));
		go1.setRadius(.25);
		go1.setTranform(trans);

		while (a.update()) {
			go.rotate(glm::vec3(1., 0., 0.), glm::radians(.8f));
			go1.rotate(glm::vec3(0., 1., 0.), glm::radians(.4f));
		}
	}
	a.terminate();
}