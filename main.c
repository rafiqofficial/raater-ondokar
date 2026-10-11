#include "raylib.h"

int main(void) {
    InitWindow(800, 600, "Loadshedding");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Hello Dhaka!", 300, 280, 30, RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}