#include "pipe.hpp"
#include "game.hpp"
#include <random>

bool game::Pipe::CheckCollision(const raylib::Rectangle &player) {
    const raylib::Vector2 scaledSize = player.GetSize() * hitboxModifier;
    const raylib::Vector2 offset = (player.GetSize() - scaledSize) / 2.0f;
    const raylib::Rectangle playerHitbox{ player.GetPosition() + offset, scaledSize };


    return top.CheckCollision(playerHitbox) || bottom.CheckCollision(playerHitbox);
}

game::Pipe::Pipe(int index) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(-200, 200);

    const float startingX = game::screenSize + (index * spacing);
    const int offsetY{ dist(gen) };

    const float topHeight{ (game::screenSize / 2) - (game::playerSize * 2) };
    const float bottomHeight{ game::screenSize - topHeight };

    top = raylib::Rectangle(startingX, 0, width, topHeight + offsetY);
    bottom = raylib::Rectangle(startingX, bottomHeight + offsetY, width, bottomHeight);
}

void game::Pipe::Draw() {
    top.Draw(GREEN);
    bottom.Draw(GREEN);
}

float game::Pipe::GetX() {
    return top.GetX();
}

bool game::Pipe::processMovement(float lastX, const raylib::Rectangle &player) {
    const float oldX{ top.GetX() };
    const float newX{ oldX < -width ? lastX + spacing : oldX - speed };

    top.SetX(newX);
    bottom.SetX(newX);

    return CheckCollision(player);
}