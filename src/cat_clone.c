// function: cat_clone
// params: argument from a string that *should* be a filename
// returns: Success/Fail integer, prints to the stdout

#include <fcntl.h>
#include <stddef.h>

int cat_clone(char *args[]) {
  // sanitize the input
  int idx = 0;
  char *args_idx = args[idx];
  while (args_idx != NULL) {
    // increase

    // track no. of speech marks.
    //
    // if speech marks == 2, break
    // if args_idx == NULL && speech marks != 2, return error.
    //
    idx++;
  }

  // idx therefore hold the length of the argument (file) that is being
  // requested in the call of the cat function.
  //
  // do something with the address of args[0] and the address of args[idx]

  // char *cat_file = args[..args_idx]
  //(NOT ACTUAL IMPLEMENTATION BECAUSE C DOES NOT HAVE ARRAY SLICING)

  // check if the file will even open, if not return error else proceed.
  /* if(!open(cat_file, O_RDONLY)) {
    return -1;
  }
  */

  return 0;
}
