// Engine.cpp
#include "pch.h"
#include "Window.h"
#include "Engine.h"

namespace {
    IRenderer* renderer = nullptr;
    Window* window = nullptr;
    RendererType rendererType = RendererType::OpenGL;
}

namespace Engine {
    void SetRenderer(RendererType type) {
        if (renderer) {
            renderer->Shutdown();
            delete renderer;
        }
        renderer = RendererFactory::CreateRenderer(type);
        rendererType = type;
    }

    void Init() {
        APIBackend backend;
        switch (rendererType) {
		case RendererType::OpenGL: backend = APIBackend::OpenGL; break;
        case RendererType::Vulkan: backend = APIBackend::Vulkan; break;
        case RendererType::Direct2D: backend = APIBackend::OpenGL; break;
        default: backend = APIBackend::OpenGL;
        }

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
