#include "hpr.h"
#include "glm/gtx/transform.hpp"

#define SPEED .1f

namespace Hpr = Hyperion;

int main(void) {
	bool succ = false;
	Hpr::Hyperion a("Test", 640, 480, succ);

	if (succ) {
		auto trans = glm::mat4(1.);

		auto go1 = a.addShape();
		go1.setType(Hpr::ShapeType::Square);
		go1.setColor(glm::vec3(1., 1., 0.));
		go1.setRadius(.5);
		go1.setTranform(trans);
		go1.setTranslation(glm::vec3(-.5, 0., 10.));
		go1.rotate(glm::vec3(0., 1., 0.), glm::radians(10.f));

		auto go2 = a.addShape();
		go2.setType(Hpr::ShapeType::Square);
		go2.setColor(glm::vec3(1., 0., 0.));
		go2.setRadius(.25);
		go2.setTranform(trans);
		go2.setTranslation(glm::vec3(.5, 0., 10.));

		while (a.update()) {
			go1.rotate(glm::vec3(1., 0., 0.), glm::radians(.8f));
			go2.rotate(glm::vec3(0., 1., 0.), glm::radians(.4f));

			//temporary way of moving the camera
			if (a.getKeyState(Hpr::KeyCode::A) == Hpr::KeyState::PRESSED) {
				go2.translate(glm::vec3(-1, 0, 0) * SPEED);
				go1.translate(glm::vec3(-1, 0, 0) * SPEED);
			}
			if (a.getKeyState(Hpr::KeyCode::D) == Hpr::KeyState::PRESSED) {
				go2.translate(glm::vec3(1, 0, 0) * SPEED);
				go1.translate(glm::vec3(1, 0, 0) * SPEED);
			}
			if (a.getKeyState(Hpr::KeyCode::W) == Hpr::KeyState::PRESSED) {
				go2.translate(glm::vec3(0, 0, -1) * SPEED);
				go1.translate(glm::vec3(0, 0, -1) * SPEED);
			}
			if (a.getKeyState(Hpr::KeyCode::S) == Hpr::KeyState::PRESSED) {
				go2.translate(glm::vec3(0, 0, 1) * SPEED);
				go1.translate(glm::vec3(0, 0, 1) * SPEED);
			}
			if (a.getKeyState(Hpr::KeyCode::SPACE) == Hpr::KeyState::PRESSED) {
				go2.translate(glm::vec3(0, 1, 0) * SPEED);
				go1.translate(glm::vec3(0, 1, 0) * SPEED);
			}
			if (a.getKeyState(Hpr::KeyCode::LEFT_SHIFT) == Hpr::KeyState::PRESSED) {
				go2.translate(glm::vec3(0, -1, 0) * SPEED);
				go1.translate(glm::vec3(0, -1, 0) * SPEED);
			}

			
		}
	}
	a.terminate();
}