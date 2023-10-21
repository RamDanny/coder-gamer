# include "constants.h"
#include "paddle.h"
#include <raylib.h>
# include <vector>

Paddle::Paddle() {
    x = 20;
    y = SCREEN_HEIGHT/2 - 40;
    spdY = 5;
}

Paddle::Paddle(float posx, float posy) {
    x = posx;
    y = posy;
    spdY = 5;
}

void Paddle::Draw() {
    DrawRectangle(x, y, PADDLE_WIDTH, PADDLE_HEIGHT, WHITE);
}

void Paddle::Move() {
    if (IsKeyDown(KEY_DOWN) && y < SCREEN_HEIGHT - spdY - PADDLE_HEIGHT) {
        y += spdY;
    }
    else if(IsKeyDown(KEY_UP) && y > spdY) {
        y -= spdY;
    }
}

void Paddle::Move(float ballY) {
    if (ballY < y) {
        y -= spdY;
    }
    else if (ballY >= y) {
        y += spdY;
    }
}

void Paddle::AutoMove(int change) {
    y += change;
}

int Paddle::getSpdY() {
    return spdY;
}

float Paddle::getX() {
    return x;
}

float Paddle::getY() {
    return y;
}
