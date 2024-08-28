#include "raylib.h"
#include "raymath.h"
#include <stdlib.h>

#define G 0.1
#define PLAYER_JUMP_SPD 350.0f
#define PLAYER_HOR_SPD 200.0f

int main(void)
{
    // Initialization
    const int screenWidth = 1080;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Not Cave Story");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);
    
    Vector2 position = {400, 400};
    Vector2 velocity = {5, 0};
    bool isjump = false;
    float width = 50, height = 100;
    
    // Main game loop
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_RIGHT) || IsKeyDown(KEY_RIGHT)) {
            if (position.x+width < screenWidth) position.x += velocity.x;
        }
        if (IsKeyPressed(KEY_LEFT) || IsKeyDown(KEY_LEFT)) {
            if (position.x > 0) position.x -= velocity.x;
        }
        if (IsKeyPressed(KEY_UP) || IsKeyDown(KEY_UP)) {
            if (!isjump) {
                isjump = true;
                velocity.y = 5;
            }
        }
        if (isjump) {
            velocity.y > -5? velocity.y -= G: velocity.y = -5;
            if (position.y - velocity.y < 400) position.y -= velocity.y;
            else {
                position.y = 500 - height;
                velocity.y = 0;
                isjump = false;
            }
        }
        // Draw
        BeginDrawing();
            ClearBackground(BLACK);
            DrawRectanglePro((Rectangle){position.x, position.y, width, height}, (Vector2){0, 0}, 0, WHITE);
            DrawRectangle(50, 500, 1000, 200, WHITE);
        EndDrawing();
    }

    // De-Initialization
    CloseWindow(); 
    return 0;
}
