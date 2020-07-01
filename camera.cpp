#include "camera.h"
#include <glm/gtc/type_ptr.hpp>

glm::mat4 Camera::GetViewMatrix()
{ 
    return glm::lookAt(position_, position_ + front_, world_up_);
}

void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
    
    float velocity = MOVEMENT_SPEED * deltaTime;
    if (direction == FORWARD)
        position_ += front_ * velocity;
    if (direction == BACKWARD)
        position_ -= front_ * velocity;
    if (direction == LEFT)
        position_ -= right_ * velocity;
    if (direction == RIGHT)
        position_ += right_ * velocity;
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset)
{
    xoffset *= SENSITIVITY;
    yoffset *= SENSITIVITY;

    yaw_ += xoffset;
    pitch_ += yoffset;

    if (pitch_ > 89.0f)
        pitch_ = 89.0f;
    if (pitch_ < -89.0f)
        pitch_ = -89.0f;

    // Update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}


void Camera::updateCameraVectors()
{
    // Calculate the new Front vector
    glm::vec3 front;
    front.x = cos(glm::radians(yaw_)) * cos(glm::radians(pitch_));
    front.y = sin(glm::radians(pitch_));
    front.z = sin(glm::radians(yaw_)) * cos(glm::radians(pitch_));
    front_ = glm::normalize(front);
     
    // Normalize the vectors, because their length gets closer to 0 the
    //more you look up or down which results in slower movement.
    right_ = glm::normalize(glm::cross(front_, world_up_));  
}

void Camera::ProcessMouseScroll(float yoffset)
{
    if (zoom_ >= 1.0f && zoom_ <= 45.0f)
        zoom_ -= yoffset;
    if (zoom_ <= 1.0f)
        zoom_ = 1.0f;
    if (zoom_ >= 45.0f)
        zoom_ = 45.0f;
}










