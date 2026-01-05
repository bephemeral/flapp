#include "player.hpp"

game::Player::Player(raylib::Vector2 screenSize) {
    raylib::Vector2 playerSize{ 50, 50 };
    raylib::Vector2 playerPos = (screenSize - playerSize) / 2.0f;

    rect = raylib::Rectangle{ playerPos, playerSize };
}

void game::Player::Draw() {
    rect.Draw(YELLOW);
}

void game::Player::processMovement() {
    bool moveKeyPressed{ raylib::Keyboard::IsKeyDown(KEY_SPACE) || raylib::Mouse::IsButtonDown(MOUSE_LEFT_BUTTON) };
    float newPlayerY{ rect.GetY() + (moveKeyPressed ? -playerSpeed : playerSpeed) };
            
    rect.SetY(newPlayerY);
}