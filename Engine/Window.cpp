#include "pch.h"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "Window.h"
#include <iostream>
#include <stdexcept>

Window::Window(const std::string& title, int width, int height, APIBackend backend) {
    this->backend = backend;

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        exit(-1);
    }

    if (backend == APIBackend::OpenGL) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }
    else if (backend == APIBackend::Vulkan) {
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    }

    windowHandle = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!windowHandle) {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        exit(-1);
    }

    if (backend == APIBackend::OpenGL) {
        glfwMakeContextCurrent(windowHandle);
    }

    if (backend == APIBackend::Vulkan) {
        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "NeoGenesis";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "NeoGenesisEngine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_3;

        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        createInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;

        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

#ifdef __APPLE__
        std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);
        extensions.push_back("VK_KHR_portability_enumeration");
        extensions.push_back("VK_KHR_get_physical_device_properties2");
        createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
        createInfo.ppEnabledExtensionNames = extensions.data();
#else
        createInfo.enabledExtensionCount = glfwExtensionCount;
        createInfo.ppEnabledExtensionNames = glfwExtensions;
#endif

        if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create Vulkan instance!");
        }

        if (glfwCreateWindowSurface(instance, windowHandle, nullptr, &surface) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create window surface!");
        }
    }

    std::cout << "[Window] Created: " << title << " (" << (backend == APIBackend::Vulkan ? "Vulkan" : "OpenGL") << ")\n";
}

Window::~Window() {
    if (windowHandle) {
        glfwDestroyWindow(windowHandle);
    }
    glfwTerminate();
    std::cout << "[Window] Destroyed\n";
}

void Window::PollEvents() {
    glfwPollEvents();
}

bool Window::ShouldClose() {
    return glfwWindowShouldClose(windowHandle);
}

void Window::SwapBuffers() {
    if (backend == APIBackend::OpenGL) {
        glfwSwapBuffers(windowHandle);
    }
}
