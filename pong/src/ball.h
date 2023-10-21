#pragma once

class Ball {
    public:
        Ball();
        void Draw();
        void Update();
        void Bounce(int);
        float getX();
        float getY();
        int getR();
    private:
        float x, y;
        int spdX, spdY;
        int radius;
};