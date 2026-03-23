#include <fcntl.h>
#include <linux/input-event-codes.h>
#include <linux/input.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

const char *key_names[256] = {
    [KEY_RESERVED] = "KEY_RESERVED",
    [KEY_ESC] = "KEY_ESC",
    [KEY_1] = "KEY_1",
    [KEY_2] = "KEY_2",
    [KEY_3] = "KEY_3",
    [KEY_4] = "KEY_4",
    [KEY_5] = "KEY_5",
    [KEY_6] = "KEY_6",
    [KEY_7] = "KEY_7",
    [KEY_8] = "KEY_8",
    [KEY_9] = "KEY_9",
    [KEY_0] = "KEY_0",
    [KEY_MINUS] = "KEY_MINUS",
    [KEY_EQUAL] = "KEY_EQUAL",
    [KEY_BACKSPACE] = "KEY_BACKSPACE",
    [KEY_TAB] = "KEY_TAB",
    [KEY_Q] = "KEY_Q",
    [KEY_W] = "KEY_W",
    [KEY_E] = "KEY_E",
    [KEY_R] = "KEY_R",
    [KEY_T] = "KEY_T",
    [KEY_Y] = "KEY_Y",
    [KEY_U] = "KEY_U",
    [KEY_I] = "KEY_I",
    [KEY_O] = "KEY_O",
    [KEY_P] = "KEY_P",
    [KEY_LEFTBRACE] = "KEY_LEFTBRACE",
    [KEY_RIGHTBRACE] = "KEY_RIGHTBRACE",
    [KEY_ENTER] = "KEY_ENTER",
    [KEY_LEFTCTRL] = "KEY_LEFTCTRL",
    [KEY_A] = "KEY_A",
    [KEY_S] = "KEY_S",
    [KEY_D] = "KEY_D",
    [KEY_F] = "KEY_F",
    [KEY_G] = "KEY_G",
    [KEY_H] = "KEY_H",
    [KEY_J] = "KEY_J",
    [KEY_K] = "KEY_K",
    [KEY_L] = "KEY_L",
    [KEY_SEMICOLON] = "KEY_SEMICOLON",
    [KEY_APOSTROPHE] = "KEY_APOSTROPHE",
    [KEY_GRAVE] = "KEY_GRAVE",
    [KEY_LEFTSHIFT] = "KEY_LEFTSHIFT",
    [KEY_BACKSLASH] = "KEY_BACKSLASH",
    [KEY_Z] = "KEY_Z",
    [KEY_X] = "KEY_X",
    [KEY_C] = "KEY_C",
    [KEY_V] = "KEY_V",
    [KEY_B] = "KEY_B",
    [KEY_N] = "KEY_N",
    [KEY_M] = "KEY_M",
    [KEY_COMMA] = "KEY_COMMA",
    [KEY_DOT] = "KEY_DOT",
    [KEY_SLASH] = "KEY_SLASH",
    [KEY_RIGHTSHIFT] = "KEY_RIGHTSHIFT",
    [KEY_LEFTALT] = "KEY_LEFTALT",
    [KEY_SPACE] = "KEY_SPACE",
    [KEY_CAPSLOCK] = "KEY_CAPSLOCK",
    [KEY_F1] = "KEY_F1",
    [KEY_F2] = "KEY_F2",
    [KEY_F3] = "KEY_F3",
    [KEY_F4] = "KEY_F4",
    [KEY_F5] = "KEY_F5",
    [KEY_F6] = "KEY_F6",
    [KEY_F7] = "KEY_F7",
    [KEY_F8] = "KEY_F8",
    [KEY_F9] = "KEY_F9",
    [KEY_F10] = "KEY_F10",
    [KEY_NUMLOCK] = "KEY_NUMLOCK",
    [KEY_SCROLLLOCK] = "KEY_SCROLLLOCK",
    [KEY_HOME] = "KEY_HOME",
    [KEY_UP] = "KEY_UP",
    [KEY_PAGEUP] = "KEY_PAGEUP",
    [KEY_LEFT] = "KEY_LEFT",
    [KEY_RIGHT] = "KEY_RIGHT",
    [KEY_END] = "KEY_END",
    [KEY_DOWN] = "KEY_DOWN",
    [KEY_PAGEDOWN] = "KEY_PAGEDOWN",
    [KEY_INSERT] = "KEY_INSERT",
    [KEY_DELETE] = "KEY_DELETE",
    [KEY_MUTE] = "KEY_MUTE",
    [KEY_VOLUMEDOWN] = "KEY_VOLUMEDOWN",
    [KEY_VOLUMEUP] = "KEY_VOLUMEUP",
    [KEY_POWER] = "KEY_POWER",
    [KEY_PAUSE] = "KEY_PAUSE",
    [KEY_LEFTMETA] = "KEY_LEFTMETA",
    [KEY_RIGHTMETA] = "KEY_RIGHTMETA",
    [KEY_MENU] = "KEY_MENU",
    [KEY_PLAYPAUSE] = "KEY_PLAYPAUSE",
    [KEY_NEXTSONG] = "KEY_NEXTSONG",
    [KEY_PREVIOUSSONG] = "KEY_PREVIOUSSONG",
    [KEY_STOPCD] = "KEY_STOPCD",
    [KEY_UNKNOWN] = "KEY_UNKNOWN",
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
      printf("%s \n", key_names[ie.code]);
    }
  }
  close(fd);
  return 0;
}
