#include "raylib-cpp.hpp"

namespace game {
    class Pipe {
    private:
        raylib::Rectangle top;
        raylib::Rectangle bottom;

        const int speed{ 2 };
    public:
        void Draw();
        bool processMovement();

        Pipe(const raylib::Vector2 &screenSize);
    };
}