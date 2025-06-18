// Engine.cpp
#include "pch.h"
#include "Engine.h"

namespace {
    IRenderer* renderer = nullptr;
}

namespace Engine {
    void SetRenderer(RendererType type) {
        if (renderer) delete renderer;
        renderer = RendererFactory::CreateRenderer(type);
    }

    void Init() { if (renderer) renderer->Init(); }
    void Draw() { if (renderer) renderer->Draw(); }
    void Shutdown() {
        if (renderer) {
            renderer->Shutdown();
            delete renderer;
            renderer = nullptr;
        }
    }
}
