#pragma once

#include "raylib-cpp.hpp"

namespace game {
    class Pipe {
    private:
        raylib::Rectangle top;
        raylib::Rectangle bottom;

        inline static constexpr int speed{ 2 };
        inline static constexpr int width{ 100 };
        inline static constexpr int spacing{ 400 };
    public:
        void Draw();
        float GetX();
        void processMovement(float lastX);

        Pipe(int index);
    };
}