// Direct2DRenderer.h
#pragma once
#include "IRenderer.h"
#include "pch.h"

class Direct2DRenderer : public IRenderer {
public:
    void Init() override;
    void Draw() override;
    void Shutdown() override;
};
