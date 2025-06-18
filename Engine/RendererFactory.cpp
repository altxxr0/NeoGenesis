// RendererFactory.cpp
#include "pch.h" // if using PCH
#include "RendererFactory.h"
#include "OpenGLRenderer.h"

namespace Engine {
    IRenderer* RendererFactory::CreateRenderer(RendererType type) {
        switch (type) {
        case RendererType::OpenGL:
            return new OpenGLRenderer();
            // Add other backends here later
        default:
            return nullptr;
        }
    }
}
