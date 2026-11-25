// function: cat_clone
// params: argument from a string that *should* be a filename
// returns: Success/Fail integer, prints to the stdout
// echo_clone is predicated on the idea that the input from
// the "shell" is sanitized before its passed to the function
// therefore cat_clone should follow suit.

#include <fcntl.h>
#include <stddef.h>

int cat_clone(char *args[]) {

  int file = 0;
  while (args[file] != NULL) {
    // check if the file will even open, if not return error else proceed.
    if (!open(args[file], O_RDONLY)) {
      return -1;
    }

    int fd = open(args[file], O_RDONLY);

    read(fd, buf, size);
  }
  return 0;
}
