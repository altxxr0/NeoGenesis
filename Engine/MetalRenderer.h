// MetalRenderer.h
#pragma once
#include "IRenderer.h"
#include "pch.h"

class MetalRenderer : public IRenderer {
public:
    void Init() override;
    void Draw() override;
    void Shutdown() override;
};
