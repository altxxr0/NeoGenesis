// Game.cpp
#include "pch.h"     // If you're using precompiled headers
#include "Game.h"
#include "../Engine/Engine.h"

namespace Game {
    void Run() {
        Engine::Init();
        Engine::Draw();
        Engine::Shutdown();
    }
}
