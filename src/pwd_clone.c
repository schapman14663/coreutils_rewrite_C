// function: pwd_clone
// params: none
// returns: Success/Fail integer, prints current working directory

#include <unistd.h>

// Just because there aren't any arguments
// doesn't mean there won't ever be and
// doesn't mean someone won't try.
int pwd_clone(char *args[]) {
  char *buf;
  size_t size = pathconf(".", _PC_PATH_MAX);

  // if the size returned from size isn't NULL,
  // get the current working directory with that
  // size as the size limit.

  getcwd(buf, size);
  return 0;
}
