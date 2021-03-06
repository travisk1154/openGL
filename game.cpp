//
// Created by tk on 3/24/20.
//

#include "game.h"
#include <iostream>

game::game()
{
    init();
}

void game::init()
{
    state = ACTIVE;
    initializeGLFW();
    initializeResourceManager();
    initializeWindowManager();
    initializeInputManager();
    initializeGLAD();
    build_camera();
}

void game::initializeResourceManager()
{
    resourceManager = new ResourceManager();
}

void game::initializeWindowManager()
{
    windowManager = new WindowManager(1024, 1024, "openGL Tutorial");
    windowManager->setKeyCallback(inputManager->key_callback);
}

void game::initializeInputManager()
{
    inputManager = InputManager::getInstance();
}

void game::build_camera()
{
    camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}

void game::build_cubes()
{
    resourceManager->loadObject("cube 1", glm::vec3( 0.0f,  0.0f,  0.0f));
    resourceManager->loadObject("cube 2", glm::vec3( 2.0f,  5.0f, -15.0f));
    resourceManager->loadObject("cube 3", glm::vec3(-1.5f, -2.2f, -2.5f));
    resourceManager->loadObject("cube 4", glm::vec3(-3.8f, -2.0f, -12.3f));
    resourceManager->loadObject("cube 5", glm::vec3( 2.4f, -0.4f, -3.5f));
    resourceManager->loadObject("cube 6", glm::vec3(-1.7f,  3.0f, -7.5f));
    resourceManager->loadObject("cube 7", glm::vec3( 1.3f, -2.0f, -2.5f));
    resourceManager->loadObject("cube 8", glm::vec3( 1.5f,  2.0f, -2.5f));
    resourceManager->loadObject("cube 9", glm::vec3( 1.5f,  0.2f, -1.5f));
    resourceManager->loadObject("cube 10", glm::vec3(-1.3f,  1.0f, -1.5f));
}

bool game::initializeGLFW()
{
    if(!glfwInit())
    {
        std::cout << "FAILED TO INITIALIZE GLFW" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    return true;
}

bool game::initializeGLAD()
{
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "FAILED TO INITIALIZE GLAD" << std::endl;
        return false;
    }

    return true;
}

void game::play()
{
    while(state != QUIT)
    {
        processInput();
        update();
        render();
        windowManager->swapBuffers();
        glfwPollEvents();

        if(windowManager->shouldClose())
        {
            state = QUIT;
        }
    }

    quit();
}

void game::quit()
{
    glfwSetWindowShouldClose(windowManager->getWindowHandle(), true);
    glfwTerminate();
}

void game::update()
{

}

void game::render()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void game::processInput()
{
    if(inputManager->isPressed(GLFW_KEY_ESCAPE))
    {
        state = QUIT;
    }

    if(inputManager->isPressed(GLFW_KEY_1) == GLFW_PRESS)
    {
        //Fill Mode
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    if(inputManager->isPressed(GLFW_KEY_2) == GLFW_PRESS)
    {
        //Wifeframe Mode
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }

    if(inputManager->isPressed(GLFW_KEY_3) == GLFW_PRESS)
    {
        //Vertex Mode
        glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
    }

    if(inputManager->isPressed( GLFW_KEY_W) == GLFW_PRESS)
    {

    }
}
