#pragma once

class Paddle {
    public:
        Paddle();
        Paddle(float, float);
        void Draw();
        void Move();
        void Move(float);
        float getX();
        float getY();
        int getSpdY();
        void AutoMove(int);
    private:
        float x, y;
        int spdX, spdY;
};

