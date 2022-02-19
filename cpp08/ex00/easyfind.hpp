#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int target) {
  typename T::iterator res =
      std::find(container.begin(), container.end(), target);
  if (res == container.end()) throw std::logic_error("Target not found.");
  return res;
}

#endif