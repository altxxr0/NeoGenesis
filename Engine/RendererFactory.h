// RendererFactory.h
#pragma once
#include "pch.h"
#include "IRenderer.h"
#include "OpenGLRenderer.h"
#include "VulkanRenderer.h"
#include "Direct2DRenderer.h"
#include "MetalRenderer.h"
#include "WebGPURenderer.h"

namespace Engine {
    class RendererFactory {
    public:
        static IRenderer* CreateRenderer(RendererType type);
    };
}
