#include "raylib-cpp.hpp"

namespace game {
    class Player {
    private:
        int screenSize;

        raylib::Rectangle rect;

        static constexpr int jumpStrength{ -10 };
        static constexpr float gravity{ 0.5f };
        float velocity{ 0 };

        bool applyVelocity();
    public:
        void Draw();
        bool processMovement();

        Player(float playerSize, int screenSize);
    };
}