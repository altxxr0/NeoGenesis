#include "../Engine/Engine.h"

int main() {
    Engine::SetRenderer(RendererType::Direct2D);
    Engine::Init();
    Engine::Run();
    Engine::Shutdown();
    return 0;
}