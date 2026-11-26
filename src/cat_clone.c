// function: cat_clone
// params: argument from a string that *should* be a filename
// returns: Success/Fail integer, prints to the stdout
// echo_clone is predicated on the idea that the input from
// the "shell" is sanitized before its passed to the function
// therefore cat_clone should follow suit.

#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>

int cat_clone(char *args[]) {
  char buf[4096];
  long long bytes_read;

  int file = 0;
  while (args[file] != NULL) {
    // check if the file will even open, if not return error else proceed.
    if (!open(args[file], O_RDONLY)) {
      return -1;
    }

    int fd = open(args[file], O_RDONLY);

    while ((bytes_read = read(fd, buf, sizeof(buf))) > 0) {
      if (write(STDOUT_FILENO, buf, bytes_read) == -1) {
        close(fd);
        return -1;
      }
    }
    close(fd);

    if (bytes_read == -1) {
      return -1;
    }
  }
  return 0;
}
