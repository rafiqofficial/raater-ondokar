#include "raylib.h"

struct Player {
    float x;
    float y;
    float speed;
};

int main(void) {
    InitWindow(800, 600, "Raater Ondokar");
    SetTargetFPS(60);

    struct Player player = {400, 300, 200};

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        // TODO: তীর চিহ্ন (ডান) চাপলে player.x বাড়াও।
        // ইঙ্গিত: if (IsKeyDown(KEY_RIGHT)) { player.x += player.speed * dt; }
    if (IsKeyDown(KEY_RIGHT)) { player.x += player.speed * dt; }
    if (IsKeyDown(KEY_LEFT)) { player.x -= player.speed * dt; }
    if (IsKeyDown(KEY_UP)) { player.y -= player.speed * dt; }
    if (IsKeyDown(KEY_DOWN)) { player.y += player.speed * dt; }

    if (player.x < 10) { player.x = 10; }
    if (player.x > 790) { player.x = 790; }
    if (player.y < 10) { player.y = 10; }
    if (player.y > 590) { player.y = 590; }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircle((int)player.x, (int)player.y, 10, RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}