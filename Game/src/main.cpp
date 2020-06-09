#include "hpr.h"
#include "glm/gtx/transform.hpp"
#include "uniformmanager/uniformmanager.h"
#include "transformation/transformation.h"
#include "glm/gtc/constants.hpp"

#include <iostream>
#include "glm/gtx/euler_angles.hpp"
#include "glm/gtx/string_cast.hpp"

#define SPEED .1f

namespace Hpr = Hyperion;

class Game : public Hpr::EventHandler {
	bool succ;
	Hpr::GameObject go1, go2, go3;
	glm::dvec2 lastPos;
	Hpr::Transformation* camera;

public:
	Game() : Hpr::EventHandler("Game", 640, 480, succ) {
		go1 = graphics.addShape();
		go1.setType(Hpr::ShapeType::Square);
		go1.setColor(glm::vec3(1., 1., 0.));
		go1.setRadius(.5);
		go1.setTranslation(glm::vec3(-1., 0., 10.));
		go1.setRotation(glm::radians(glm::vec3(0.f)));

		go2 = graphics.addShape();
		go2.setType(Hpr::ShapeType::Square);
		go2.setColor(glm::vec3(1., 0., 0.));
		go2.setRadius(.5);
		go2.setTranslation(glm::vec3(10., 0., 0.));
		go2.setRotation(glm::radians(glm::vec3(0.f)));

		go2 = graphics.addShape();
		go2.setType(Hpr::ShapeType::Square);
		go2.setColor(glm::vec3(1., 0., 1.));
		go2.setRadius(.5);
		go2.setTranslation(glm::vec3(0., -10., 0.));
		go2.setRotation(glm::radians(glm::vec3(0.f)));

		go3 = graphics.addShape();
		go3.setType(Hpr::ShapeType::Square);
		go3.setColor(glm::vec3(0., 0., 1.));
		go3.setRadius(.5);
		go3.setTranslation(glm::vec3(0., 10., 0.));
		go3.setRotation(glm::radians(glm::vec3(0.f)));

		camera = &graphics.getCameraTransformation();

		getMousePos(lastPos);
	}

	void onUpdate() {
		//go1.setTranslation(go1.getTransformation().getTranslation() + glm::vec3(.01, 0., 0.));

		moveCamera();

		rotateCamera();

		std::cout << glm::to_string(camera->getTranslation()) << " " << glm::to_string(glm::degrees(camera->getRotation())) << std::endl;
	}

	void rotateCamera() {
		auto dpos = lastPos;
		getMousePos(lastPos);
		dpos -= lastPos;

		auto newRot = camera->getRotation() + glm::vec3(dpos.x, dpos.y, 0) * .01f;

		//clamp y axis
		auto yDeg = glm::degrees(newRot.y);
		if (yDeg >= 90 && yDeg <= 180) {
			newRot.y = .5 * glm::pi<float>();
		}
		else if(yDeg <= 270 && yDeg >= 180) {
			newRot.y = 1.5 * glm::pi<float>();
		}

		camera->setRotation(newRot);
	}

	void moveCamera() {

		if (getKeyState(Hpr::KeyCode::W) == Hpr::KeyState::PRESSED) {
			moveBy(getForward());
		}
		if (getKeyState(Hpr::KeyCode::S) == Hpr::KeyState::PRESSED) {
			moveBy(-getForward());
		}
		if (getKeyState(Hpr::KeyCode::A) == Hpr::KeyState::PRESSED) {
			moveBy(-getRight());
		}
		if (getKeyState(Hpr::KeyCode::D) == Hpr::KeyState::PRESSED) {
			moveBy(getRight());
		}
		if (getKeyState(Hpr::KeyCode::SPACE) == Hpr::KeyState::PRESSED) {
			moveBy(glm::vec3(0., 1., 0.));
		}
		if (getKeyState(Hpr::KeyCode::LEFT_SHIFT) == Hpr::KeyState::PRESSED) {
			moveBy(glm::vec3(0., -1., 0.));
		}
	}

	inline void moveBy(const glm::vec3& dir) {
		camera->setTranslation(camera->getTranslation() + dir * SPEED);
	}

	inline glm::vec3 getForward() {
		return glm::cross(glm::vec3(0, 1, 0), getRight());
	}

	inline glm::vec3 getRight() {
		float xAngle = camera->getRotation().x;
		return glm::vec3(glm::cos(xAngle), 0, -glm::sin(xAngle));
	}
};

int main(void) {
	Game a;
	a.update();
}