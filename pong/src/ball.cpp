# include "constants.h"
#include "ball.h"
#include <raylib.h>

int SCORE_PL = 0;
int SCORE_AI = 0;

Ball::Ball() {
    radius = 10;
    x = SCREEN_WIDTH/2 - radius;
    y = SCREEN_HEIGHT/2 - radius;
    spdX = 7;
    spdY = 7;
}

void Ball::Draw() {
    DrawCircle(x, y, radius, WHITE);
}

void Ball::Update() {
    x += spdX;
    y += spdY;
    if (x + radius > GetScreenWidth()) {
        SCORE_AI++;
    }
    else if (x - radius < 0) {
        SCORE_PL++;
    }
    DrawText(TextFormat("%i", SCORE_AI), SCREEN_WIDTH/2 - 150, 300, 80, WHITE);
    DrawText(TextFormat("%i", SCORE_PL), SCREEN_WIDTH/2 + 150, 300, 80, WHITE);
}

void Ball::Bounce(int b) {
    if (b == 1) {
        spdX = 0-spdX;
    }
    if (b == 2) {
        spdY = -spdY;
    }
    if (x > SCREEN_WIDTH - radius || x < radius) {
        spdX = 0-spdX;
    }
    if (y > SCREEN_HEIGHT - radius || y < radius) {
        spdY = 0-spdY;
    }
}

float Ball::getX() {
    return x;
}

float Ball::getY() {
    return y;
}

int Ball::getR() {
    return radius;
}
