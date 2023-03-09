#include "raylib.h"

int main() {

  float character_pos[2] = {
      400, 250}; // temporarily hard coded this to be the centre of the screen

  InitWindow(800, 500, "GIP");
  SetTargetFPS(60);

  char alphabet_holder[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                              'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                              's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  int random_alphabet = GetRandomValue(0, 25);

  while (!WindowShouldClose()) {

    char text_message[2] = {alphabet_holder[random_alphabet], '\0'};

    if (IsKeyPressed(65)) {
      random_alphabet = GetRandomValue(
          0,
          25); // assign an integer value to the key type (eg KEY_A is int 65)
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawText(text_message, 400, 250, 40,
             LIGHTGRAY); // takes a String (character array) as an argument, not
                         // a char data type

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
