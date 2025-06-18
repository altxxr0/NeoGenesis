// Direct2DRenderer.h
#pragma once
#include "IRenderer.h"
#include "pch.h"
#pragma comment(lib, "d2d1.lib")
#include <d2d1.h>

class Direct2DRenderer : public IRenderer {
public:
    Direct2DRenderer();
    ~Direct2DRenderer();
    void Init() override;
    void Draw() override;
    void Shutdown() override;
private:
    ID2D1Factory* pFactory = nullptr;
    ID2D1HwndRenderTarget* pRenderTarget = nullptr;
    HWND hwnd = nullptr;
};
