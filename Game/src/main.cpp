#include "hpr.h"
#include "glm/gtx/transform.hpp"

#include <iostream>
#include "glm/gtx/string_cast.hpp"

#define SPEED .1f

namespace Hpr = Hyperion;

class Game : public Hpr::EventHandler {
	bool succ;
	Hpr::GameObject go1;
	glm::dvec2 prevPos;

public:
	Game() : Hpr::EventHandler("Game", 640, 480, succ) {
		go1 = graphics.addShape();
		go1.setType(Hpr::ShapeType::Square);
		go1.setColor(glm::vec3(1., 1., 0.));
		go1.setRadius(.5);
		go1.setTranform(glm::mat4(1.));
		go1.setTranslation(glm::vec3(-.5, 0., 10.));
		go1.rotate(glm::vec3(0., 1., 0.), glm::radians(10.f));

		getMousePos(prevPos);
	}

	void onUpdate() {
		//temporary way of moving the camera
		if (getKeyState(Hpr::KeyCode::A) == Hpr::KeyState::PRESSED) {
			go1.translate(glm::vec3(-1, 0, 0) * SPEED);
		}
		if (getKeyState(Hpr::KeyCode::D) == Hpr::KeyState::PRESSED) {
			go1.translate(glm::vec3(1, 0, 0) * SPEED);
		}
		if (getKeyState(Hpr::KeyCode::W) == Hpr::KeyState::PRESSED) {
			go1.translate(glm::vec3(0, 0, -1) * SPEED);
		}
		if (getKeyState(Hpr::KeyCode::S) == Hpr::KeyState::PRESSED) {
			go1.translate(glm::vec3(0, 0, 1) * SPEED);
		}
		if (getKeyState(Hpr::KeyCode::SPACE) == Hpr::KeyState::PRESSED) {
			go1.translate(glm::vec3(0, 1, 0) * SPEED);
		}
		if (getKeyState(Hpr::KeyCode::LEFT_SHIFT) == Hpr::KeyState::PRESSED) {
			go1.translate(glm::vec3(0, -1, 0) * SPEED);
		}

		//temporary way of rotating the camera
		glm::dvec2 pos;
		getMousePos(pos);
		auto dpos = pos - prevPos;

		if (dpos != glm::dvec2(0.)) {
			go1.rotateAxes(-glm::vec3(dpos.y, dpos.x, 0.), glm::atan(glm::length(dpos) / 100.));
		}

		prevPos = pos;

	}

	void onKeyPress(Hpr::KeyCode key, Hpr::KeyState state) {
		if (state == Hpr::KeyState::PRESSED) {
			auto a = go1.getColor();
			switch (key) {
			case Hpr::KeyCode::Q:
				a += glm::vec3(.2, 0., 0.);
				go1.setColor(a);
				break;
			case Hpr::KeyCode::E:
				a -= glm::vec3(.2, 0., 0.);
				go1.setColor(a);
				break;
			}
		}
	}
};

int main(void) {
	Game a;
	a.update();
}