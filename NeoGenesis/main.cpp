#include "../Engine/Engine.h"

int main() {
    Engine::SetRenderer(RendererType::OpenGL);
    Engine::Init();
    Engine::Run();
    Engine::Shutdown();
    return 0;
}

