// function: pwd_clone
// params: none
// returns: Success/Fail integer, prints current working directory

#include <stdlib.h>
#include <unistd.h>

// Just because there aren't any arguments
// doesn't mean there won't ever be and
// doesn't mean someone won't try.
int pwd_clone(char *args[]) {
  (void)args;

  char *buf;
  char *ptr;
  long size = pathconf(".", _PC_PATH_MAX);

  if (size <= 0) {
    return -1;
  }
  // if the size returned from size isn't NULL,
  // get the current working directory with that
  // size as the size limit.
  buf = (char *)malloc(size);
  if (!buf) {
    return -1;
  }

  ptr = getcwd(buf, size);

  if (!ptr) {
    free(buf);
    return -1;
  }

  size_t ptr_len = 0;
  while (ptr[ptr_len] != '\0') {
    ptr_len++;
  }

  write(STDOUT_FILENO, ptr, ptr_len);
  write(STDOUT_FILENO, "\n", 1);
  free(buf);
  return 0;
}
