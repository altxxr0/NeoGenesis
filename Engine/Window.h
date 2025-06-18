#pragma once
#include <string>
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

enum class APIBackend { OpenGL, Vulkan };

class Window {
public:
    Window(const std::string& title, int width, int height, APIBackend backend);
    ~Window();

    void PollEvents();
    bool ShouldClose();
    void SwapBuffers();

private:
    GLFWwindow* windowHandle = nullptr;
    APIBackend backend = APIBackend::OpenGL;

    // Vulkan-specific
    VkInstance instance = VK_NULL_HANDLE;
    VkSurfaceKHR surface = VK_NULL_HANDLE;
};
