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

    Camera2D camera = { 0 };
    camera.target = position;
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    bool camcatchup_x = false,  camcatchup_y = false;
    float camdiff_x = 0, camdiff_y = 0, camvel_x = 7, camvel_y = 7, camdamp_x = 0, camdamp_y = 0;
    
    // Main game loop
    while (!WindowShouldClose())
    {
        if (abs(position.x - camera.target.x) > (0.3*screenWidth)) {
            camcatchup_x = true;
            camdiff_x = position.x - camera.target.x;
        }
        else if (abs(position.y - camera.target.y) > (0.3*screenHeight)) {
            camcatchup_y = true;
            camdiff_y = position.y - camera.target.y;
        }
        if (camcatchup_x) {
            if (camdiff_x > 0) {
                camera.target.x += camvel_x-camdamp_x;
            }
            else if (camdiff_x < 0) {
                camera.target.x -= camvel_x-camdamp_x;
            }
            /*if ((camdiff_x > 0 && (position.x - camera.target.x) < (0.3*screenWidth)) || (camdiff_x < 0 && (position.x - camera.target.x) > (0.3*screenWidth)) || camdiff_x == 0) {
                camdamp_x = camvel_x/2;
            }
            else*/ if ((camdiff_x > 0 && (position.x - camera.target.x) < 0) || (camdiff_x < 0 && (position.x - camera.target.x) > 0) || camdiff_x == 0) {
                camcatchup_x = false;
                camdiff_x = 0;
                camdamp_x = 0;
            }
            else camdiff_x = position.x - camera.target.x;
        }
        else if (camcatchup_y) {
            if (camdiff_y > 0) {
                camera.target.y += camvel_y-camdamp_y;
            }
            else if (camdiff_y < 0) {
                camera.target.y -= camvel_y-camdamp_y;
            }
            /*if ((camdiff_y > 0 && (position.y - camera.target.y) < (0.3*screenHeight)) || (camdiff_y < 0 && (position.y - camera.target.y) > (0.3*screenHeight)) || camdiff_y == 0) {
                camdamp_y = camvel_y/2;
            }
            else*/ if ((camdiff_y > 0 && (position.y - camera.target.y) < 0) || (camdiff_y < 0 && (position.y - camera.target.y) > 0) || camdiff_y == 0) {
                camcatchup_y = false;
                camdiff_y = 0;
                camdamp_y = 0;
            }
            else camdiff_y = position.y - camera.target.y;
        }

        if (IsKeyPressed(KEY_RIGHT) || IsKeyDown(KEY_RIGHT)) {
            //if (position.x+width < screenWidth) position.x += velocity.x;
            position.x += velocity.x;
        }
        if (IsKeyPressed(KEY_LEFT) || IsKeyDown(KEY_LEFT)) {
            //if (position.x > 0) position.x -= velocity.x;
            position.x -= velocity.x;
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
            BeginMode2D(camera);
            //DrawRectangleLines(350, 400, 50, 100, WHITE);
            DrawRectanglePro((Rectangle){position.x, position.y, width, height}, (Vector2){0, 0}, 0, WHITE);
            DrawRectangle(-250, 500, 1500, 200, WHITE);
            EndMode2D();
        EndDrawing();
    }

    // De-Initialization
    CloseWindow(); 
    return 0;
}
