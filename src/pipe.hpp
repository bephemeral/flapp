#pragma once

#include "raylib-cpp.hpp"

namespace game {
    class Pipe {
    private:
        raylib::Rectangle top;
        raylib::Rectangle bottom;

        bool dead{ false };

        inline static constexpr int speed{ 3 };
        inline static constexpr int width{ 75 };
        inline static constexpr float hitboxModifier{ 0.8 };
        inline static constexpr int spacing{ 300 };

        bool CheckCollision(const raylib::Rectangle &player);
    public:
        void Draw();
        float GetX();
        bool processMovement(float lastX, const raylib::Rectangle &player);

        Pipe(int index);
    };
}