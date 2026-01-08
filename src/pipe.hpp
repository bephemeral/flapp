#pragma once

#include "raylib-cpp.hpp"

namespace game {
    class Pipe {
    private:
        raylib::Rectangle top;
        raylib::Rectangle bottom;

        inline static constexpr int speed{ 2 };
        inline static constexpr int width{ 100 };
    public:
        void Draw();
        void processMovement();

        Pipe();
    };
}