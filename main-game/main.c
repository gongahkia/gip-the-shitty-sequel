#include "raylib.h"
#include <stdio.h>

int main() {

  float character_pos[2] = {
      400, 250}; // temporarily hard coded this to be the centre of the screen

  InitWindow(800, 500, "GIP");
  SetTargetFPS(60);

  // randomise the value of the random_alphabet input, and print it to the
  // screen with drawtext void function
  int random_alphabet = GetRandomValue(1, 26);

  char alphabet_holder[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                              'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                              's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  while (!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawCircle(character_pos[0], character_pos[1], 20.0, MAGENTA);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}