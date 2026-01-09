#pragma once

#include "raylib-cpp.hpp"
#include "game.hpp"

namespace game {
    class Player {
    private:
        inline static constexpr int playerPos{ (game::screenSize - game::playerSize) / 2 };
        raylib::Rectangle rect{ playerPos, playerPos, game::playerSize, game::playerSize };

        inline static constexpr float jumpStrength{ -600.0f };
        inline static constexpr float gravity{ 2000.0f };
        float velocity{ 0 };

        bool applyVelocity();
    public:
        void Draw();

        const raylib::Rectangle& getRect() const;
        bool processMovement();
    };
}