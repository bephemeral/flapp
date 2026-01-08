#include "raylib-cpp.hpp"

namespace game {
    class Pipe {
    private:
        raylib::Rectangle top;
        raylib::Rectangle bottom;

        static constexpr int speed{ 2 };
        static constexpr int width{ 100 };
    public:
        void Draw();
        void processMovement();

        Pipe(float playerSize, int screenSize);
    };
}