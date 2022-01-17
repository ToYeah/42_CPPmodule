#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

std::string OpenInputFile(char* file_name) {
  std::ifstream input_file_stream(file_name);

  input_file_stream.exceptions(std::ios::badbit);

  if (!input_file_stream) {
    std::cout << "Unable to read Inputfile" << std::endl;
    std::exit(1);
  }

  std::ostringstream receiver;
  receiver << input_file_stream.rdbuf();
  return receiver.str();
}

void ReplaceString(std::string& str, std::string s1, std::string s2) {
  size_t index = 0;
  while (1) {
    index = str.find(s1, index);

    if (index == std::string::npos) {
      break;
    }

    str.erase(index, s1.size());
    str.insert(index, s2);
    index += s2.size();
  }
}

void OutputReplasedString(std::string& str, std::string file_name) {
  std::ofstream output_file_stream((file_name + ".replace").c_str());
  output_file_stream.exceptions(std::ios::badbit);

  if (!output_file_stream) {
    std::cout << "Unable to open Outputfile" << std::endl;
    std::exit(1);
  }

  output_file_stream << str;
  output_file_stream.close();
}

int main(int argc, char** argv) {
  std::cout.exceptions(std::ios::badbit);

  try {
    if (argc != 4) {
      std::cout << "Invalid argument!" << std::endl;
      return (0);
    }

    std::string str = OpenInputFile(argv[1]);
    ReplaceString(str, argv[2], argv[3]);
    OutputReplasedString(str, argv[1]);

  } catch (const std::exception& e) {
    std::cout << e.what() << '\n';
  }
}