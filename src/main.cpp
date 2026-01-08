#include "raylib-cpp.hpp"
#include "game.hpp"
#include "player.hpp"
#include "pipe.hpp"
#include <array>

int main() {
    raylib::Window window{ game::screenSize, game::screenSize, "Flapp" };

    game::Player player{};

    std::array<game::Pipe, 3> pipes = { game::Pipe(0), game::Pipe(1), game::Pipe(2) };

    SetTargetFPS(60);

    while (!window.ShouldClose())
    {
        BeginDrawing();
        {
            window.ClearBackground(BLUE);

            float lastX{ pipes.back().GetX() };
            for (auto& pipe : pipes) {
                pipe.processMovement(lastX);
                pipe.Draw();

                lastX = pipe.GetX();
            }

            if(!player.processMovement()) {
                break;
            }
            player.Draw();
        }
        EndDrawing();
    }

    return 0;
}