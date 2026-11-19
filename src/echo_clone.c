// Write what you know. Fill in the gaps later.

// function: echo_clone
// params: string input
// returns: Success/Fail integer, prints input to the stdout

// To include the ability to parse the following escape sequences:
// - \n new line
// - \r carriage return
// - \t horizontal tab
// - \v vertical tab
// - \b backspace
// - \a alert
// - \\ escape backslash

#include <stddef.h>
#include <unistd.h>

int echo_clone(char *args[]) {

  int outer_index = 0;
  char *outer_string = args[outer_index];

  // Loop through the whole input
  while (outer_string != NULL) {
    int inner_index = 0;
    char current_char = outer_string[inner_index];

    // Loop through each word in the original input
    while (outer_string[inner_index] != '\0') {

      // Check for escape character, peak at the next
      // character to determine how to handle it
      if (outer_string[inner_index] == '\\') {
        char next_char = outer_string[inner_index + 1];

        switch (next_char) {
        case 'n':
          current_char = '\n';
          inner_index++;
          break;
        case 'r':
          current_char = '\r';
          inner_index++;
          break;
        case 't':
          current_char = '\t';
          inner_index++;
          break;
        case 'v':
          current_char = '\v';
          inner_index++;
          break;
        case '\\':
          current_char = '\\';
          inner_index++;
          break;
        case 'c':
          return 0;
        }
      }
      write(STDOUT_FILENO, &current_char, 1);
      inner_index++;
      current_char = outer_string[inner_index];
    }
    outer_index++;
    outer_string = args[outer_index];
    if (outer_string != NULL) {
      write(STDOUT_FILENO, " ", 1);
    }
  }
  write(STDOUT_FILENO, "\n", 1);
  return 0;
}
