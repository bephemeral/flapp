#include "pipe.hpp"
#include "game.hpp"
#include <random>

game::PipeCollision game::Pipe::CheckCollision(const raylib::Rectangle& player) {
    const raylib::Rectangle playerHitbox(
        player.GetX() + player.GetWidth()  * (1.0f - hitboxModifier) * 0.5f,
        player.GetY() + player.GetHeight() * (1.0f - hitboxModifier) * 0.5f,
        player.GetWidth()  * hitboxModifier,
        player.GetHeight() * hitboxModifier
    );

    if (top.CheckCollision(playerHitbox) || bottom.CheckCollision(playerHitbox))
        return game::PipeCollision::Collision;

    const float pipeCenterX = top.GetX() + width / 2.0f;
    const float playerCenterX = player.GetX() + player.GetWidth() / 2.0f;

    if (!scored && playerCenterX > pipeCenterX) {
        scored = true;
        return game::PipeCollision::Scored;
    }

    return game::PipeCollision::None;
}

game::Pipe::Pipe(int index) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(-175, 175);

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

game::PipeCollision game::Pipe::processMovement(float lastX, const raylib::Rectangle& player) {
    const float oldX{ top.GetX() };

    if (oldX < -width) {
        const float resetTo = lastX + spacing;

        top.SetX(resetTo);
        bottom.SetX(resetTo);
        
        scored = false;
    } else {
        const float newX{ oldX - (speed * GetFrameTime()) };

        top.SetX(newX);
        bottom.SetX(newX);
    }

    return CheckCollision(player);
}
