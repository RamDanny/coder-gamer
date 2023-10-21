# include "constants.h"
# include <raylib.h>
# include "ball.h"
# include "paddle.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong by RD");
    SetTargetFPS(60);
    Ball ball;
    Paddle p1(1, SCREEN_HEIGHT/2 - 40);
    Paddle p2(SCREEN_WIDTH - 21, SCREEN_HEIGHT/2 - 40);
    int BOUNCE_FLAG = 0;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        ball.Update();
        DrawLine(SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT, WHITE);
        p1.Draw();
        ball.Draw();
        ball.Bounce(0);
        p2.Draw();
        p2.Move();
        if (CheckCollisionCircleRec(Vector2{ball.getX(), ball.getY()}, ball.getR(), Rectangle{p2.getX()-1, p2.getY()-1, PADDLE_WIDTH+2, PADDLE_HEIGHT+2})) {
            if (ball.getX() >= p2.getX() && (ball.getY() <= p2.getY() || ball.getY() >= p2.getY() + PADDLE_WIDTH) && BOUNCE_FLAG == 0) {
                ball.Bounce(2);
                BOUNCE_FLAG = 1;
            }
            else ball.Bounce(1);
        }
        else if (CheckCollisionCircleRec(Vector2{ball.getX(), ball.getY()}, ball.getR(), Rectangle{p1.getX()-1, p1.getY()-1, PADDLE_WIDTH+2, PADDLE_HEIGHT+2})) {
            if (ball.getX() <= p1.getX() && (ball.getY() <= p1.getY() || ball.getY() >= p1.getY() + PADDLE_WIDTH) && BOUNCE_FLAG == 0) {
                ball.Bounce(2);
                BOUNCE_FLAG = 1;
            }
            else ball.Bounce(1);
        }
        else BOUNCE_FLAG = 0;
        if (p1.getY() > ball.getY()) {
            p1.AutoMove(-p1.getSpdY()-1);
        }
        else if (p1.getY() < ball.getY()) {
            p1.AutoMove(p1.getSpdY()+1);
        }
        EndDrawing();
    }
    return 0;
}
