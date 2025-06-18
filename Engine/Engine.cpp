// Engine.cpp
#include "pch.h"
#include "Window.h"
#include "Engine.h"

namespace {
    IRenderer* renderer = nullptr;
    Window* window = nullptr;
    RendererType rendererType = RendererType::OpenGL;  // <== Added definition here
}

namespace Engine {
    void SetRenderer(RendererType type) {
        if (renderer) {
            renderer->Shutdown();
            delete renderer;
        }
        renderer = RendererFactory::CreateRenderer(type);
        rendererType = type; // <== Save selected renderer type here
    }

    void Init() {
        APIBackend backend = (rendererType == RendererType::Vulkan) ? APIBackend::Vulkan : APIBackend::OpenGL;
        window = new Window("NeoGenesis", 1280, 720, backend);
        if (renderer) renderer->Init();
    }

    void Run() {
        while (!window->ShouldClose()) {
            window->PollEvents();
            if (renderer) renderer->Draw();
            window->SwapBuffers();
        }
    }

    void Shutdown() {
        if (renderer) {
            renderer->Shutdown();
            delete renderer;
            renderer = nullptr;
        }
        delete window;
        window = nullptr;
    }
}
