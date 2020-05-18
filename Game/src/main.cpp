#include "hpr.h"
#include "glm/gtx/transform.hpp"

#include <iostream>
#include "glm/gtx/euler_angles.hpp"
#include "glm/gtx/string_cast.hpp"
#include "uniformmanager/uniformmanager.h"

#define SPEED .1f

namespace Hpr = Hyperion;

class Game : public Hpr::EventHandler {
	bool succ;
	Hpr::GameObject go1, go2, go3;
	glm::dvec2 initMouse;

public:
	Game() : Hpr::EventHandler("Game", 640, 480, succ) {
		go1 = graphics.addShape();
		go1.setType(Hpr::ShapeType::Square);
		go1.setColor(glm::vec3(1., 1., 0.));
		go1.setRadius(.5);
		go1.setTranform(glm::mat4(1.));
		go1.setTranslation(glm::vec3(-1., 0., 10.));
		go1.rotate(glm::vec3(0., 1., 0.), glm::radians(10.f));

		go2 = graphics.addShape();
		go2.setType(Hpr::ShapeType::Sphere);
		go2.setColor(glm::vec3(1., 0., 1.));
		go2.setRadius(.5);
		go2.setTranform(glm::mat4(1.));
		go2.setTranslation(glm::vec3(1., 0., 10.));

		go3 = graphics.addShape();
		go3.setType(Hpr::ShapeType::Square);
		go3.setColor(glm::vec3(1., 1., 1.));
		go3.setRadius(.5);
		go3.setTranform(glm::mat4(1.));
		go3.setTranslation(glm::vec3(0., -2.5, 0.));

		getMousePos(initMouse);
	}

	void onUpdate() {
		auto camera = graphics.getUniformManager().getUniform<Hpr::Transformation>(Hpr::UniformType::Camera);
		glm::dvec2 mousePos;
		getMousePos(mousePos);
		auto dMouse = (initMouse - mousePos) * .01;

		rotateCamera(camera, dMouse);
		moveCamera(camera);

		graphics.getUniformManager().setUniform<Hpr::Transformation>(Hpr::UniformType::Camera, camera);

	}

	void rotateCamera(Hpr::Transformation& camera, const glm::dvec2& dMouse) {
		auto clampedY = dMouse.y > 1.5f ? 1.5f : dMouse.y;
		camera.setRotation(glm::eulerAngleXY(dMouse.y, dMouse.x));
	}

	void moveCamera(Hpr::Transformation& camera) {
		if (getKeyState(Hpr::KeyCode::W) == Hpr::KeyState::PRESSED) {
			camera.translate(glm::vec3(0., 0., -1.) * SPEED);
		}
		if (getKeyState(Hpr::KeyCode::S) == Hpr::KeyState::PRESSED) {
			camera.translate(glm::vec3(0., 0., 1.) * SPEED);
		}
		if (getKeyState(Hpr::KeyCode::A) == Hpr::KeyState::PRESSED) {
			camera.translate(glm::vec3(-1., 0., 0.) * SPEED);
		}
		if (getKeyState(Hpr::KeyCode::D) == Hpr::KeyState::PRESSED) {
			camera.translate(glm::vec3(1., 0., 0.) * SPEED);
		}
		if (getKeyState(Hpr::KeyCode::SPACE) == Hpr::KeyState::PRESSED) {
			camera.translate(glm::vec3(0., 1., 0.) * SPEED);
		}
		if (getKeyState(Hpr::KeyCode::LEFT_SHIFT) == Hpr::KeyState::PRESSED) {
			camera.translate(glm::vec3(0., -1., 0.) * SPEED);
		}
	}
};

int main(void) {
	Game a;
	a.update();
}