#include "pipe.hpp"
#include "game.hpp"
#include <random>

game::Pipe::Pipe() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(-200, 200);

    const int offset{ dist(gen) };
    const float topHeight{ (game::screenSize / 2) - (game::playerSize * 2) };
    const float bottomHeight{ game::screenSize - topHeight };

    top = raylib::Rectangle{ game::screenSize, 0, width, topHeight + offset };
    bottom = raylib::Rectangle{ game::screenSize, bottomHeight + offset, width, bottomHeight };
}

void game::Pipe::Draw() {
    top.Draw(GREEN);
    bottom.Draw(GREEN);
}

void game::Pipe::processMovement() {
    const float oldX{ top.GetX() };
    const float newX{ oldX == 0 ? game::screenSize : oldX - speed };

    top.SetX(newX);
    bottom.SetX(newX);
}