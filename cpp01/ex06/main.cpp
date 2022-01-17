#include "Karen.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Invalid argument!";
  } else {
    Karen karen;
    karen.complain(argv[1]);
  }
}