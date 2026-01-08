#include "player.hpp"
#include "game.hpp"

void game::Player::Draw() {
    rect.Draw(YELLOW);
}

const raylib::Rectangle& game::Player::getRect() const {
    return rect;
}

bool game::Player::applyVelocity() {
    velocity += gravity;

    float newY{ rect.GetY() + velocity };
    newY = std::max(newY, 0.0f);

    if (newY > screenSize) {
        return true;
    }

    rect.SetY(newY);
    return false;
}

bool game::Player::processMovement() {
    bool moveKeyPressed{ raylib::Keyboard::IsKeyPressed(KEY_SPACE) || raylib::Mouse::IsButtonPressed(MOUSE_LEFT_BUTTON) };
    if (moveKeyPressed) {
        velocity = jumpStrength;
    }
     
    return applyVelocity();
}