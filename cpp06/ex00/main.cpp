#include "Convert.hpp"

int main(int argc, char** argv) {
  try {
    if (argc != 2) {
      std::cout << "Invalid argument!" << std::endl;
      return 1;
    }
    std::string original_value = argv[1];

    FormatTypes type = judgeArgumentFormat(original_value);
    printConvertedValues(original_value, type);
  } catch (const std::exception& e) {
    printValues(NULL, NULL, NULL, NULL);
  }
}