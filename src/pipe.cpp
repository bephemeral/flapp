#include "pipe.hpp"
#include <random>

game::Pipe::Pipe(float playerSize, int screenSize) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(-200, 200);

    const int offset{ dist(gen) };
    const float topHeight{ (screenSize / 2) - (playerSize * 2) };
    const float bottomHeight{ screenSize - topHeight };

    top = raylib::Rectangle{ screenSize, 0, width, topHeight + offset };
    bottom = raylib::Rectangle{ screenSize, bottomHeight + offset, width, bottomHeight };
}

void game::Pipe::Draw() {
    top.Draw(GREEN);
    bottom.Draw(GREEN);
}

void game::Pipe::processMovement() {
    top.SetX(top.GetX() - speed);
    bottom.SetX(bottom.GetX() - speed);
}