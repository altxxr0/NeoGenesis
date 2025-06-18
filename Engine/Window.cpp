#include "pch.h"
#include "Window.h"
#include <GLFW/glfw3.h>
#include <iostream>

Window::Window(const std::string& title, int width, int height) {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        exit(-1);
    }

    // OpenGL version (you can change this)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window
    windowHandle = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!windowHandle) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(static_cast<GLFWwindow*>(windowHandle));
    std::cout << "[Window] Created: " << title << "\n";
}

Window::~Window() {
    glfwDestroyWindow(static_cast<GLFWwindow*>(windowHandle));
    glfwTerminate();
    std::cout << "[Window] Destroyed\n";
}

void Window::PollEvents() {
    glfwPollEvents();
}

bool Window::ShouldClose() {
    return glfwWindowShouldClose(static_cast<GLFWwindow*>(windowHandle));
}

void Window::SwapBuffers() {
    glfwSwapBuffers(static_cast<GLFWwindow*>(windowHandle));
}
