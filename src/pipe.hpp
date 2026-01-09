#pragma once

#include "raylib-cpp.hpp"

namespace game {
    enum class PipeCollision {
        None,
        Scored,
        Collision
    };

    class Pipe {
    private:
        raylib::Rectangle top;
        raylib::Rectangle bottom;

        bool scored{ false };

        inline static constexpr int speed{ 200 };
        inline static constexpr int width{ 75 };
        inline static constexpr float hitboxModifier{ 0.8 };
        inline static constexpr int spacing{ 300 };

        PipeCollision CheckCollision(const raylib::Rectangle &player);
    public:
        void Draw();
        float GetX();
        PipeCollision processMovement(float lastX, const raylib::Rectangle &player);

        Pipe(int index);
    };
}