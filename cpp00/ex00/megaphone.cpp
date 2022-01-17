#include <iostream>

void printArgumentsUpperCase(int argc, char **argv) {
  for (size_t i = 1; i < static_cast<size_t>(argc); i++) {
    char *s = argv[i];
    while (*s != '\0') {
      std::cout << static_cast<char>(std::toupper(*s++));
    }
  }
}

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  } else {
    printArgumentsUpperCase(argc, argv);
  }
  std::cout << std::endl;
}