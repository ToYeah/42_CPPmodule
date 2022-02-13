#include <iostream>

template <typename T>
void iter(T* ary, size_t len, void (*fn)(T&)) {
  for (size_t i = 0; i < len; i++) {
    fn(ary[i]);
  }
}

template <typename T>
void print(T& val) {
  std::cout << val << std::endl;
}