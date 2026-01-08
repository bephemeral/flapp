#include "raylib-cpp.hpp"
#include "game.hpp"
#include "player.hpp"
#include "pipe.hpp"
#include <array>

namespace game {
    int score{ 0 };
}

int main() {
    raylib::Window window{ game::screenSize, game::screenSize, "Flapp" };

    raylib::Text scoreText("0", 50);

    game::Player player{};

    std::array<game::Pipe, 3> pipes = { game::Pipe(0), game::Pipe(1), game::Pipe(2) };

    SetTargetFPS(60);

    while (!window.ShouldClose()) {
        BeginDrawing();
        window.ClearBackground(BLUE);

        if(player.processMovement())
            return 0;

        player.Draw();

        const raylib::Rectangle& playerRect{ player.getRect() };
        float lastX{ pipes.back().GetX() };
        for (auto& pipe : pipes) {
            if(pipe.processMovement(lastX, playerRect))
                return 0;

            pipe.Draw();

            lastX = pipe.GetX();
        }

        scoreText.SetText(std::to_string(game::score));
        scoreText.Draw(10, 10);

        EndDrawing();
    }

    return 0;
}