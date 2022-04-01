#include "Collider.h"

GOAT_ENGINE::Collider::Collider(): position(glm::vec2()), size(glm::vec2()), isActive(false) {
}

GOAT_ENGINE::Collider::Collider(glm::vec2 _position, glm::vec2 _size, bool _active): position(_position), size(_size), isActive(_active) {
}

void GOAT_ENGINE::Collider::update(glm::vec2 newPos, glm::vec2 newSize){
	this->position = newPos;
	this->size = newSize;
}

bool GOAT_ENGINE::Collider::isColliding(Collider other) {
	if (!other.isActive || !this->isActive) {
		return false; 
	}

	const glm::vec2 points[] = { 
		glm::vec2(this->position.x - (this->size.x / 2.0f), this->position.y - (this->size.y / 2.0f)), 
		glm::vec2(this->position.x + (this->size.x / 2.0f), this->position.y - (this->size.y / 2.0f)),
		glm::vec2(this->position.x + (this->size.x / 2.0f), this->position.y + (this->size.y / 2.0f)),
		glm::vec2(this->position.x - (this->size.x / 2.0f), this->position.y + (this->size.y / 2.0f))
	};
	const glm::vec2 otherPoints[] = {
		glm::vec2(other.position.x - (other.size.x / 2.0f), other.position.y - (other.size.y / 2.0f)),
		glm::vec2(other.position.x + (other.size.x / 2.0f), other.position.y - (other.size.y / 2.0f)),
		glm::vec2(other.position.x + (other.size.x / 2.0f), other.position.y + (other.size.y / 2.0f)),
		glm::vec2(other.position.x - (other.size.x / 2.0f), other.position.y + (other.size.y / 2.0f))
	};

	bool isCollidingX(points[0].x <= otherPoints[1].x && points[1].x >= otherPoints[0].x);
	bool isCollidingY(points[0].y <= otherPoints[2].y && points[2].y >= otherPoints[0].y);
	return isCollidingX && isCollidingY;
}

void GOAT_ENGINE::Collider::setActive(bool active) {
	this->isActive = active;
}