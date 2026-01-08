#pragma once

#include "raylib-cpp.hpp"
#include "game.hpp"

namespace game {
    class Player {
    private:
        inline static constexpr int playerPos{ (game::screenSize - game::playerSize) / 2 };
        raylib::Rectangle rect{ playerPos, playerPos, game::playerSize, game::playerSize };

        inline static constexpr int jumpStrength{ -10 };
        inline static constexpr float gravity{ 0.5f };
        float velocity{ 0 };

        bool applyVelocity();
    public:
        void Draw();

        raylib::Rectangle getRect();
        bool processMovement();
    };
}