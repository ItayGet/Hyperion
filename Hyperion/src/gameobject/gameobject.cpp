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

	const Transformation& GameObject::getTransformation() {
		return (sm->getTransformations()[index]);
	}

	void GameObject::setTransformation(const Transformation& transformation) {
		sm->getTransformations()[index] = transformation;
	}

	GameObject::GameObject() : sm(nullptr), index(-1) {}

	void GameObject::_wireSm(ShapeManager* sm, unsigned int index) {
		this->sm = sm;
		this->index = index;
	}

	const glm::vec3& GameObject::getColor() {
		return getShape().getColor();
	}

	void GameObject::setColor(const glm::vec3& color) {
		informUpdate();
		getShape().setColor(glm::vec4(color, 1.));
	}

	const glm::vec3& GameObject::getSize() {
		return getShape().getSize();
	}

	void GameObject::setSize(const glm::vec3& size) {
		informUpdate();
		getShape().setSize(glm::vec4(size, 1.));
	}


	ShapeType GameObject::getType() {
		return getShape().getType();
	}

	void GameObject::setType(ShapeType type) {
		informUpdate();
		getShape().setType(type);
	}

	void GameObject::setTranslation(const glm::vec3& translation) {
		informUpdate();
		((Transformation&)getTransformation()).setTranslation(translation);
	}

	void GameObject::setRotation(const glm::vec3& rotation) {
		informUpdate();
		((Transformation&)getTransformation()).setRotation(rotation);
	}
}