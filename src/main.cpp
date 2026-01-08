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

    while (!window.ShouldClose()) {
        BeginDrawing();
        window.ClearBackground(BLUE);

        const raylib::Rectangle playerRect{ player.getRect() };
        float lastX{ pipes.back().GetX() };
        for (auto& pipe : pipes) {
            if(pipe.processMovement(lastX, playerRect))
                return 0;

            pipe.Draw();

            lastX = pipe.GetX();
        }

        if(player.processMovement())
            return 0;

        player.Draw();
        EndDrawing();
    }

    return 0;
}