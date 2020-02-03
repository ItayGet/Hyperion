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

	void GameObject::multiplyByMat(const glm::mat4& mat) {
		informUpdate();
		glm::mat4 newTrans = getShape().getTransform() * mat;
		getShape().setTransform(newTrans);
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
		auto pos = getTranslation();
		auto trans = getTransform();

		//ugly, but it works
		clearTranslation((glm::mat4&)trans);

		trans = glm::rotate(trans, angle, axis);
		trans = glm::translate(trans, pos);

		setTranform(trans);
	}

	void GameObject::translate(const glm::vec3& point) {
		multiplyByMat(glm::translate(glm::mat4(1.), point));
	}

	glm::vec3 GameObject::getTranslation() {
		return glm::vec3(glm::inverse(getTransform()) * glm::vec4(glm::vec3(0.), 1.)) * -1.f;
	}

	void GameObject::setTranslation(const glm::vec3& translation) {
		//ugly, but it works
		clearTranslation((glm::mat4&)getTransform());
		translate(translation);
	}

	glm::mat4 GameObject::getRotation() {
		glm::mat4 tmp = getTransform();
		clearTranslation(tmp);
		return tmp;
	}

	void GameObject::setRotation(const glm::mat4& rotation) {
		glm::vec3 pos = getTranslation();
		setTranform(rotation);
		setTranslation(pos);
	}
}