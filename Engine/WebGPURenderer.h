// WebGPURenderer.h
#pragma once
#include "IRenderer.h"
#include "pch.h"

class WebGPURenderer : public IRenderer {
public:
    void Init() override;
    void Draw() override;
    void Shutdown() override;
};
