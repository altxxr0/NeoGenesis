#include "pch.h"
#include "Direct2DRenderer.h"

#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <iostream>

Direct2DRenderer::Direct2DRenderer() {}

Direct2DRenderer::~Direct2DRenderer() {}

void Direct2DRenderer::Init() {
    std::cout << "[Direct2D] Initializing\n";

    // Get the GLFW window from the current OpenGL/Vulkan context
    GLFWwindow* glfwWindow = static_cast<GLFWwindow*>(glfwGetCurrentContext());
    if (!glfwWindow) {
        std::cerr << "[Direct2D] Failed to get GLFW context\n";
        return;
    }

    hwnd = glfwGetWin32Window(glfwWindow); // Get HWND from GLFW

    // Create the factory
    D2D1_FACTORY_OPTIONS options = {};
    if (FAILED(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, options, &pFactory))) {
        std::cerr << "[Direct2D] Failed to create factory\n";
        return;
    }

    RECT rc;
    GetClientRect(hwnd, &rc);
    D2D1_SIZE_U size = D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top);

    D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties();
    D2D1_HWND_RENDER_TARGET_PROPERTIES hwndProps = D2D1::HwndRenderTargetProperties(hwnd, size);

    if (FAILED(pFactory->CreateHwndRenderTarget(props, hwndProps, &pRenderTarget))) {
        std::cerr << "[Direct2D] Failed to create render target\n";
        return;
    }
}

void Direct2DRenderer::Draw() {
    std::cout << "[Direct2D] Drawing Frame\n";
    if (pRenderTarget) {
        pRenderTarget->BeginDraw();
        pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::SkyBlue)); // Example clear
        pRenderTarget->EndDraw();
    }
}

void Direct2DRenderer::Shutdown() {
    std::cout << "[Direct2D] Shutdown\n";
    if (pRenderTarget) { pRenderTarget->Release(); pRenderTarget = nullptr; }
    if (pFactory) { pFactory->Release(); pFactory = nullptr; }
}
