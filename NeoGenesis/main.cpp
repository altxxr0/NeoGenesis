#include "../Engine/Engine.h"

int main() {
    Engine::SetRenderer(RendererType::OpenGL);
    Engine::Init();

    for (int i = 0; i < 3; ++i) {
        Engine::Draw();
    }

    Engine::Shutdown();
    return 0;
}
