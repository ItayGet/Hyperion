#include "gameobject.h"
#include "glm/gtx/transform.hpp"

#include <iostream>
#include "glm/gtx/string_cast.hpp"

namespace Hyperion {
	Shape& GameObject::getShape() {
		return (sm->getShapes()->shapes)[index];
	}

	void GameObject::informUpdate() {
		if (sm == nullptr) { return; }
		sm->addQueue(index);
	}

	void GameObject::multiplyByMat(const glm::mat4& mat) {
		informUpdate();
		glm::mat4 newTrans = getShape().getTransform() * mat;
		getShape().setTransform(newTrans);
	}

	GameObject::GameObject() {}

	void GameObject::_wireSm(ShapeManager* sm, unsigned int index) {
		this->sm = sm;
		this->index = index;
	}

	glm::mat4 GameObject::getTransform() {
		return getShape().getTransform();
	}

	void GameObject::setTranform(glm::mat4 transform) {
		informUpdate();
		getShape().setTransform(transform);
	}

	glm::vec3 GameObject::getColor() {
		return getShape().getColor();
	}

	void GameObject::setColor(glm::vec3 color) {
		informUpdate();
		getShape().setColor(glm::vec4(color, 1.));
	}

	float GameObject::getRadius() {
		return getShape().getRadius();
	}

	void GameObject::setRadius(float radius) {
		informUpdate();
		getShape().setRadius(radius);
	}

	ShapeType GameObject::getType() {
		return getShape().getType();
	}

	void GameObject::setType(ShapeType type) {
		informUpdate();
		getShape().setType(type);
	}

	// Rotate along origin of shape
	void GameObject::rotate(glm::vec3 axis, float angle) {
		//TODO: change when changing setters/getters to refrences

		auto trans = getTransform();

		glm::vec3 pos = glm::vec3(glm::inverse(trans) * glm::vec4(glm::vec3(0.), 1.)) * -1.f;

		trans[3] = glm::vec4(glm::vec3(0.), 1.);

		trans = glm::rotate(trans, angle, axis);

		trans = glm::translate(trans, pos);

		setTranform(trans);
	}

	void GameObject::translate(glm::vec3 point) {
		multiplyByMat(glm::translate(glm::mat4(1.), point));
	}
}