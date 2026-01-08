#include "raylib-cpp.hpp"
#include "game.hpp"
#include "player.hpp"
#include "pipe.hpp"

int main() {
    raylib::Window window{ game::screenSize, game::screenSize, "Flapp" };

    game::Player player{};
    game::Pipe pipe{};

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