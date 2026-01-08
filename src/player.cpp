#include "player.hpp"
#include "game.hpp"

void game::Player::Draw() {
    rect.Draw(YELLOW);
}

bool game::Player::applyVelocity() {
    velocity += gravity;

    float newY{ rect.GetY() + velocity };
    newY = std::max(newY, 0.0f);

    if (newY > screenSize) {
        return false;
    }

    rect.SetY(newY);
    return true;
}

bool game::Player::processMovement() {
    bool moveKeyPressed{ raylib::Keyboard::IsKeyPressed(KEY_SPACE) || raylib::Mouse::IsButtonPressed(MOUSE_LEFT_BUTTON) };
    if (moveKeyPressed) {
        velocity = jumpStrength;
    }
     
    return applyVelocity();
}