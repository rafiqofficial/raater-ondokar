#include "raylib.h"
#include <stdbool.h>
#include <math.h>

int main(void) {
    InitWindow(800, 600, "Wave Test");
    InitAudioDevice();            // sound system chalu
    SetTargetFPS(60);

    // code diye ekta beep toiri (440 Hz, 0.25 second)
    Wave wave = {0};
    wave.frameCount = 44100 / 4;
    wave.sampleRate = 44100;
    wave.sampleSize = 16;
    wave.channels = 1;
    short *samples = (short *)MemAlloc(wave.frameCount * sizeof(short));
    for (unsigned int i = 0; i < wave.frameCount; i++) {
        float t = (float)i / wave.sampleRate;
        float fade = 1.0f - (float)i / wave.frameCount;   // dhire dhire kome
        samples[i] = (short)(sinf(2 * PI * 440 * t) * fade * 12000);
    }
    wave.data = samples;
    Sound beep = LoadSoundFromWave(wave);
    UnloadWave(wave);

    Vector2 center = {0, 0};
    float radius = 0;
    bool active = false;

    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            center = GetMousePosition();
            radius = 0;
            active = true;
            PlaySound(beep);      // click korle sound baje
        }

        if (active) {
            radius += 3;
            if (radius > 300) active = false;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        if (active) {
            DrawCircleLines((int)center.x, (int)center.y, radius, SKYBLUE);
        }
        EndDrawing();
    }

    UnloadSound(beep);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}