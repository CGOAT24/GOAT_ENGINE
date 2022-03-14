#include "Collider.h"

Collider::Collider(): position(glm::vec2()), size(glm::vec2()), isActive(false) {
}

Collider::Collider(glm::vec2 _position, glm::vec2 _size, bool _active): position(_position), size(_size), isActive(_active) {
}

void Collider::update(glm::vec2 newPos, glm::vec2 newSize){
	this->position = newPos;
	this->size = newSize;
}

bool Collider::isColliding(Collider other) {
	if (!other.isActive || !this->isActive) {
		return false;
	}

	bool isColliding(false);
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

	if (otherPoints[2].y >= points[0].y && otherPoints[2].x >= points[0].x && otherPoints[2].y <= points[2].y && otherPoints[2].x <= points[2].x) {
		isColliding = true;
	}
	else if (otherPoints[3].y >= points[1].y && otherPoints[3].x <= points[1].x && otherPoints[3].y <= points[3].y && otherPoints[3].x >= points[3].x) {
		isColliding = true;
	}
	else if (otherPoints[0].y <= points[2].y && otherPoints[0].x <= points[2].x && otherPoints[0].y >= points[0].y && otherPoints[0].x >= points[0].x) {
		isColliding = true;
	}
	else if (otherPoints[1].y <= points[3].y && otherPoints[1].x >= points[3].x && otherPoints[1].y >= points[1].y && otherPoints[1].x <= points[1].x) {
		isColliding = true;
	}
	return isColliding;
}

void Collider::setActive(bool active) {
	this->isActive = active;
}