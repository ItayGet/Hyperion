#include "gameobject.h"
#include "glm/gtx/transform.hpp"

namespace Hyperion {
	Shape& GameObject::getShape() {
		return (sm->getShapes()->shapes)[index];
	}

	void GameObject::informUpdate() {
		if (sm == nullptr) { return; }
		sm->addQueue(index);
	}

	Transformation& GameObject::getTransformation() {
		return (Transformation&)getTransform();
	}

	GameObject::GameObject() : sm(nullptr), index(-1) {}

	void GameObject::_wireSm(ShapeManager* sm, unsigned int index) {
		this->sm = sm;
		this->index = index;
	}

	void GameObject::clearTranslation(glm::mat4& mat) {
		mat[3] = glm::vec4(glm::vec3(0.), 1.);
	}

	const glm::mat4& GameObject::getTransform() {
		return getShape().getTransform();
	}

	void GameObject::setTranform(const glm::mat4& transform) {
		informUpdate();
		getShape().setTransform(transform);
	}

	const glm::vec3& GameObject::getColor() {
		return getShape().getColor();
	}

	void GameObject::setColor(const glm::vec3& color) {
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
	void GameObject::rotate(const glm::vec3& axis, float angle) {
		informUpdate();
		getTransformation().rotate(axis, angle);
	}

	// Rotate along axes
	void GameObject::rotateAxes(const glm::vec3& axis, float angle) {
		informUpdate();
		getTransformation().rotateAxes(axis, angle);
	}

	void GameObject::translate(const glm::vec3& point) {
		informUpdate();
		getTransformation().translate(point);
	}

	glm::vec3 GameObject::getTranslation() {
		return getTransformation().getTranslation();
	}

	void GameObject::setTranslation(const glm::vec3& translation) {
		informUpdate();
		getTransformation().setTranslation(translation);
	}

	glm::mat4 GameObject::getRotation() {
		return getTransformation().getRotation();
	}

	void GameObject::setRotation(const glm::mat4& rotation) {
		informUpdate();
		getTransformation().setRotation(rotation);
	}
}