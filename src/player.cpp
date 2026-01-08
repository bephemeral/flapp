#include "player.hpp"

game::Player::Player(float playerSize, int screenSize) : screenSize(screenSize) {
    const int playerPos = (screenSize - playerSize) / 2; // centers player, assumes window is square

    rect = raylib::Rectangle{ playerPos, playerPos, playerSize, playerSize };
}

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