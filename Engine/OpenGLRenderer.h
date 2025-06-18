// OpenGLRenderer.h
#pragma once
#include "IRenderer.h"

class OpenGLRenderer : public IRenderer {
public:
    void Init() override;
    void Draw() override;
    void Shutdown() override;
};
