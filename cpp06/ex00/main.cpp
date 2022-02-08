#include "Converter.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Invalid argument!" << std::endl;
    return;
  }

  Converter convertor(argv[1]);
  std::cout << convertor << std::endl;
}