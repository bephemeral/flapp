#include "raylib-cpp.hpp"
#include "player.hpp"
#include "pipe.hpp"

int main() {
    static constexpr int screenSize{ 600 };
    static constexpr int playerSize{ 50 };

    raylib::Window window{ screenSize, screenSize, "Flapp" };

    game::Player player{ playerSize, screenSize };
    game::Pipe pipe{ playerSize, screenSize };

    SetTargetFPS(60);

    while (!window.ShouldClose())
    {
        BeginDrawing();
        {
            window.ClearBackground(BLUE);

            pipe.processMovement();
            pipe.Draw();

            if(!player.processMovement()) {
                break;
            }
            player.Draw();
        }
        EndDrawing();
    }

    return 0;
}