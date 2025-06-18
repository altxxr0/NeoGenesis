// IRenderer.h
#pragma once

enum class RendererType {
    OpenGL,
    Vulkan,
    Direct2D,
    Metal,
    WebGPU
};

class IRenderer {
public:
    virtual ~IRenderer() = default;
    virtual void Init() = 0;
    virtual void Draw() = 0;
    virtual void Shutdown() = 0;
};
