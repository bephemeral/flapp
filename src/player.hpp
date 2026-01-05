#include "raylib-cpp.hpp"

namespace game {
    class Player {
    private:
        int screenHeight;

        raylib::Rectangle rect;

        const int jumpStrength{ -10 };
        const float gravity{ 0.5f };
        float velocity{ 0 };

        void applyVelocity();
    public:
        void Draw();
        void processMovement();

        Player(const raylib::Vector2 &screenSize);
    };
}