#include "raylib-cpp.hpp"

namespace game {
    class Player {
    private:
        raylib::Rectangle rect;
        int playerSpeed{ 3 };
    public:
        void Draw();
        void processMovement();

        Player(raylib::Vector2 screenSize);
    };
}