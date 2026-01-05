#include "player.hpp"

game::Player::Player(const raylib::Vector2 &screenSize) {
    raylib::Vector2 playerSize{ 50, 50 };
    raylib::Vector2 playerPos = (screenSize - playerSize) / 2.0f;

    rect = raylib::Rectangle{ playerPos, playerSize };
}

void game::Player::Draw() {
    rect.Draw(YELLOW);
}

void game::Player::processMovement() {
    bool moveKeyPressed{ raylib::Keyboard::IsKeyPressed(KEY_SPACE) || raylib::Mouse::IsButtonPressed(MOUSE_LEFT_BUTTON) };
    if (moveKeyPressed) {
        velocity = jumpStrength;
    }
     
    velocity += gravity;
    rect.SetY(rect.GetY() + velocity);
}