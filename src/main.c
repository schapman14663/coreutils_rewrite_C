#include "cloneutils.h"
int main() {
  char *test_echo1[] = {"This\n", "is\r",   "a\t",       "test\v", "of",
                        "the\a",  "echo\\", "function!", NULL};

  // char *cat_test[] = {,
  //                   NULL};
  echo_clone(test_echo1);

  pwd_clone(test_echo1);

  cat_clone(cat_test);
  return 0;
}
