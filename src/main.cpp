#include "raylib-cpp.hpp"
#include "player.hpp"

int main() {
    raylib::Vector2 screenSize{ 800, 450 };

    raylib::Window window{ screenSize.x, screenSize.y, "Flapp" };

    game::Player player{ screenSize };

    SetTargetFPS(60);

    while (!window.ShouldClose())
    {
        BeginDrawing();
        {
            window.ClearBackground(BLUE);

            player.Draw();
            player.processMovement();
        }
        EndDrawing();
    }

    return 0;
}