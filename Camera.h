#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

class Camera {
public:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    float yaw;
    float pitch;
    float fov;
    float speed;
    float sensitivity;

    Camera(glm::vec3 startPos = glm::vec3(0.0f, 0.0f, 3.0f));
    glm::mat4 getViewMatrix();
    void processKeyboard(int key, float deltaTime);
    void processMouseMovement(float xoffset, float yoffset);
    void processScroll(float yoffset);
};

