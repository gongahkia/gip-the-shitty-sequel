#include "raylib.h"
#include <stdio.h>
#include <string.h>

int main() {

  // ------------

  // ~generic window initialization~
  InitWindow(800, 500, "GIP");
  SetTargetFPS(60);

  // ------------

  // ~game objects~
  char alphabet_holder[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                              'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                              's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  int random_alphabet = GetRandomValue(0, 25);

  int player_score = 0;

  // ------------

  // ~main game loop~
  while (!WindowShouldClose()) {

    // ------------

    // ~update every turn~
    // intialize character shown on screen with the zero character to indicate
    // the termination of a string
    char text_message[2] = {alphabet_holder[random_alphabet], '\0'};
    char str_player_score[3];
    char score_message[17] = "Player Score: ";
    sprintf(str_player_score, "%d", player_score);
    strcat(score_message, str_player_score);

    if (player_score > 4) {
      BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawText("You win!", 350, 250, 30, BLACK);
    }

    // assign an integer value to the key type (KEY_A
    // is 65, KEY_Z is 90)
    if (IsKeyPressed(random_alphabet + 65)) {
      player_score++;
      random_alphabet = GetRandomValue(0, 25);
    }

    // ------------

    // ~drawing the game to the screen~
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // DrawText() takes a String (character array) as an
    // argument, not a char data type
    DrawText(text_message, 400, 250, 40, LIGHTGRAY);
    DrawText(score_message, 600, 50, 15, BLACK);

    EndDrawing();
  }

  // ------------

  // ~de-initialization of game window~
  CloseWindow();

  return 0;
}
