#pragma once
#include <string>

class Window {
public:
    Window(const std::string& title, int width, int height);
    ~Window();

    void PollEvents();   // Process input
    bool ShouldClose();  // Query window close
    void SwapBuffers();  // Swap the window's framebuffer

private:
    void* windowHandle;  // GLFWwindow*
};
