#include <fcntl.h>
#include <linux/input-event-codes.h>
#include <linux/input.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
const char *key_names[256] = {
    [KEY_ESC] = "ESC",     [KEY_1] = "1",
    [KEY_2] = "2",         [KEY_3] = "3",
    [KEY_4] = "4",         [KEY_5] = "5",
    [KEY_6] = "6",         [KEY_7] = "7",
    [KEY_8] = "8",         [KEY_9] = "9",
    [KEY_0] = "0",         [KEY_MINUS] = "-",
    [KEY_EQUAL] = "=",     [KEY_BACKSPACE] = "BACKSPACE",
    [KEY_TAB] = "TAB",     [KEY_Q] = "Q",
    [KEY_W] = "W",         [KEY_E] = "E",
    [KEY_R] = "R",         [KEY_T] = "T",
    [KEY_Y] = "Y",         [KEY_U] = "U",
    [KEY_I] = "I",         [KEY_O] = "O",
    [KEY_P] = "P",         [KEY_ENTER] = "ENTER",
    [KEY_A] = "A",         [KEY_S] = "S",
    [KEY_D] = "D",         [KEY_F] = "F",
    [KEY_G] = "G",         [KEY_H] = "H",
    [KEY_J] = "J",         [KEY_K] = "K",
    [KEY_L] = "L",         [KEY_Z] = "Z",
    [KEY_X] = "X",         [KEY_C] = "C",
    [KEY_V] = "V",         [KEY_B] = "B",
    [KEY_N] = "N",         [KEY_M] = "M",
    [KEY_SPACE] = "SPACE",
};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("usage: %s eventX\n", argv[0]);
    return 1;
  }
  char dest[256] = "/dev/input/";
  strncat(dest, argv[1], 8);
  int fd = open(dest, O_RDONLY, 0);
  printf("file descriptor: %d", fd);
  if (fd < 0) {
    printf("error unable open for reading '%s'\n", dest);
    return (0);
  }
  while (1) {
    struct input_event ie;
    read(fd, &ie, sizeof(ie));
    if (ie.value == 1 && ie.type == EV_KEY) {

      printf("Key: %s \n", key_names[ie.code]);
    }
  }
  close(fd);
  return 0;
}
