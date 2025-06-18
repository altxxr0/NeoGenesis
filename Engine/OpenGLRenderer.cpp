// OpenGLRenderer.cpp
#include "pch.h" // only if you're using PCH
#include "OpenGLRenderer.h"
#include <iostream> // For now we just simulate

void OpenGLRenderer::Init() {
    std::cout << "[OpenGL] Initialized\n";
}

void OpenGLRenderer::Draw() {
    std::cout << "[OpenGL] Drawing Frame\n";
}

void OpenGLRenderer::Shutdown() {
    std::cout << "[OpenGL] Shutdown\n";
}
