// RendererFactory.cpp
#include "pch.h" // if using PCH
#include "RendererFactory.h"
#include "OpenGLRenderer.h"
#include "VulkanRenderer.h"
#include "Direct2DRenderer.h"
#include "MetalRenderer.h"
#include "WebGPURenderer.h"

namespace Engine {
    IRenderer* RendererFactory::CreateRenderer(RendererType type) {
        switch (type) {
        case RendererType::OpenGL:
            return new OpenGLRenderer();
        case RendererType::Vulkan:
            return new VulkanRenderer();
        case RendererType::Direct2D:
            return new Direct2DRenderer();
        case RendererType::Metal:
            return new MetalRenderer();
        case RendererType::WebGPU:
            return new WebGPURenderer();
            
        default:
            return nullptr;
        }
    }
}
