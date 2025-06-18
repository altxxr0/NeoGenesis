// VulkanRenderer.h
#pragma once
#include "pch.h"
#include "IRenderer.h" // Ensure IRenderer is included


class VulkanRenderer : public IRenderer {
public:
    void Init() override;
    void Draw() override;
    void Shutdown() override;
};
