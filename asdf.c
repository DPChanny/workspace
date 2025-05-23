#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void wait(const char *message, const char trigger);

void main() {
  const char *asdf = "asdf";

  float time;
  int count;
  char i, buffer;

  wait("Press S to start", 's');

  while (1) {
    count = 0;
    i = 0;

    clock_t start = clock();
    while (1) {
      buffer = _getche();
      rewind(stdin);
      if (buffer != asdf[i])
        break;
      i++;
      if (i >= strlen(asdf))
        i = 0;
      count++;
    }
    clock_t end = clock();

    time = (float)(end - start) / CLOCKS_PER_SEC;

    // clang-format off
    printf("\ntime: %fs, count: %d, speed: %f\n",
      time,
      (int)(count / 4),
      1 / (time / count));
    // clang-format on

    wait("Press R to restart", 'r');
  }
}

void wait(const char *message, const char trigger) {
  printf("%s", message);
  char buffer;
  while (1) {
    buffer = _getch();
    rewind(stdin);
    if (tolower(buffer) == tolower(trigger))
      break;
  }
  system("cls");
}