// Engine.h
#pragma once
#include "IRenderer.h"
#include "RendererFactory.h"

namespace Engine {
    void SetRenderer(RendererType type); // <!>
    void Init();                         // <!>
    void Draw();                         // <!>
    void Shutdown();                     // <!>
}
