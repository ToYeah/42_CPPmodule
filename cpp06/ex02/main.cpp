#include "Identify.hpp"

int main() {
  std::srand(static_cast<unsigned int>(std::time(NULL)));
  Base* res1 = generate();
  Base* res2 = generate();

  std::cout << "ptr: ";
  identify(res1);
  std::cout << "ref: ";
  identify(*res2);
  delete res1;
  delete res2;
  return 0;
}