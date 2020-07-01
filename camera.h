#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>;
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <vector>

// Defines several possible options for camera movement. Used as abstraction 
// to stay away from window-system specific input methods
enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

constexpr GLfloat MOVEMENT_SPEED =  2.5f;
const float SENSITIVITY =  0.1f;


class Camera
{
public:
    // Camera Attributes
    glm::vec3 position_;
    glm::vec3 front_;
    glm::vec3 world_up_;
    glm::vec3 up_;
    glm::vec3 right_;
    // Euler Angles
    GLfloat yaw_;
    GLfloat pitch_;
   
    GLfloat zoom_ = 45.0f;
       
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f), 
                                glm::vec3 world_up = glm::vec3(0.0f, 1.0f, 0.0f), 
                                GLfloat yaw = -90,
                                GLfloat pitch = 0) :
                                front_(glm::vec3(0.0f, 0.0f, -1.0f))
                                
    {
        position_ = position;
        world_up_ = world_up;
        yaw_ = yaw;
        pitch_ = pitch;
        updateCameraVectors();
    }
    // Constructor with scalar values
    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) :
           front_(glm::vec3(0.0f, 0.0f, -1.0f))
    {
        position_ = glm::vec3(posX, posY, posZ);
        world_up_ = glm::vec3(upX, upY, upZ);
        yaw_ = yaw;
        pitch_ = pitch;
        updateCameraVectors();
    }

    // Returns the view matrix calculated using Euler Angles and the LookAt Matrix
    glm::mat4 GetViewMatrix();
    // Processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
    void ProcessKeyboard(Camera_Movement direction, float deltaTime);
      // Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
    void ProcessMouseMovement(float xoffset, float yoffset);
       // Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
    void ProcessMouseScroll(float yoffset);
 
private:
    // Calculates the front vector from the Camera's (updated) Euler Angles
    void updateCameraVectors();
   
};



#endif