#include "pipe.hpp"

game::Pipe::Pipe(float playerSize, int screenSize) {
    const float topHeight = (screenSize / 2) - (playerSize * 2);
    const float bottomHeight = screenSize - topHeight;

    top = raylib::Rectangle{ screenSize, 0, width, topHeight };
    bottom = raylib::Rectangle{ screenSize, bottomHeight, width, bottomHeight };
}

void game::Pipe::Draw() {
    top.Draw(GREEN);
    bottom.Draw(GREEN);
}

void game::Pipe::processMovement() {
    top.SetX(top.GetX() - speed);
    bottom.SetX(bottom.GetX() - speed);
}