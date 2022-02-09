#include "Convert.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Invalid argument!" << std::endl;
    return 1;
  }
  std::string original_value = argv[1];
  FormatTypes type = judgeArgumentFormat(original_value);
  std::cout << type << std::endl;
}