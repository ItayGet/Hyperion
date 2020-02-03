#include "hpr.h"
#include "glm/gtx/transform.hpp"

namespace Hpr = Hyperion;

int main(void) {
	bool succ = false;
	Hpr::Hyperion a("Test", 640, 480, succ);

	if (succ) {
		auto trans = glm::mat4(1.);

		auto go = a.addShape();
		go.setType(Hpr::ShapeType::Square);
		go.setColor(glm::vec3(1., 1., 0.));
		go.setRadius(.5);
		go.setTranform(trans);
		go.translate(glm::vec3(-.5, 1., 10.));
		go.rotate(glm::vec3(0., 1., 0.), glm::radians(10.f));

		auto go1 = a.addShape();
		go1.setType(Hpr::ShapeType::Square);
		go1.setColor(glm::vec3(1., 0., 0.));
		go1.setRadius(.25);
		go1.setTranform(trans);
		go1.setTranslation(glm::vec3(.5, 0., 10.));

		while (a.update()) {
			go.rotate(glm::vec3(1., 0., 0.), glm::radians(.8f));
			go1.rotate(glm::vec3(0., 1., 0.), glm::radians(.4f));
		}
	}
	a.terminate();
}