// RendererFactory.h
#pragma once
#include "IRenderer.h"
#include "OpenGLRenderer.h"
// #include "VulkanRenderer.h" ...

namespace Engine {
    class RendererFactory {
    public:
        static IRenderer* CreateRenderer(RendererType type);
    };
}
