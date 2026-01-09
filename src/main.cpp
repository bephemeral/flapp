#include "raylib-cpp.hpp"
#include "game.hpp"
#include "player.hpp"
#include "pipe.hpp"
#include <array>
#include <string>

int main() {
    raylib::Window window{ game::screenSize, game::screenSize, "Flapp" };

    int score{ 0 };
    raylib::Text scoreText("0", 50, WHITE, GetFontDefault(), 2);

    game::Player player{};

    std::array<game::Pipe, 3> pipes = { game::Pipe(0), game::Pipe(1), game::Pipe(2) };

    while (!window.ShouldClose()) {
        BeginDrawing();
        window.ClearBackground(BLUE);

        if(player.processMovement())
            return 0;

        player.Draw();

        const raylib::Rectangle& playerRect{ player.getRect() };
        float lastX{ pipes.back().GetX() };
        for (auto& pipe : pipes) {
            switch (pipe.processMovement(lastX, playerRect)) {
                case game::PipeCollision::None:
                    break;
                case game::PipeCollision::Scored:
                    scoreText.SetText(std::to_string(++score));
                    break;
                case game::PipeCollision::Collision:
                    return 0;
            }

            pipe.Draw();

            lastX = pipe.GetX();
        }

        scoreText.Draw(10, 10);

        EndDrawing();
    }

    return 0;
}