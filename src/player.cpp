#include "player.hpp"

game::Player::Player(const raylib::Vector2 &screenSize) {
    screenHeight = screenSize.y;

    raylib::Vector2 playerSize{ 50, 50 };
    raylib::Vector2 playerPos = (screenSize - playerSize) / 2.0f;

    rect = raylib::Rectangle{ playerPos, playerSize };
}

void game::Player::Draw() {
    rect.Draw(YELLOW);
}

void game::Player::applyVelocity() {
    velocity += gravity;

    float newY{ rect.GetY() + velocity };
    newY = std::max(newY, 0.0f);

    if (newY > screenHeight) {
        exit(0);
    }

    rect.SetY(newY);
}

void game::Player::processMovement() {
    bool moveKeyPressed{ raylib::Keyboard::IsKeyPressed(KEY_SPACE) || raylib::Mouse::IsButtonPressed(MOUSE_LEFT_BUTTON) };
    if (moveKeyPressed) {
        velocity = jumpStrength;
    }
     
    applyVelocity();
}