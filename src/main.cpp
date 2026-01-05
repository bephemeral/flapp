#include "raylib-cpp.hpp"

int main() {
    raylib::Vector2 screenSize{ 800, 450 };

    raylib::Window window{ screenSize.x, screenSize.y, "Flapp" };

    raylib::Vector2 rectSize{ 50, 50 };
    raylib::Vector2 rectPos = (screenSize - rectSize) / 2.0f;
    raylib::Rectangle rect{ rectPos, rectSize };

    SetTargetFPS(60);

    while (!window.ShouldClose())
    {
        BeginDrawing();

        window.ClearBackground(BLUE);

        rect.Draw(YELLOW);

        EndDrawing();
    }

    return 0;
}