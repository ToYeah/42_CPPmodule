#include <iostream>

#include "MutantStack.hpp"

typedef MutantStack<int> int_mstack;

void print_stack(int_mstack stack) {
  for (int_mstack::iterator it = stack.begin(); it != stack.end(); it++) {
    std::cout << *it << ", ";
  }
  std::cout << std::endl;
}

int main() {
  {
    std::cout << "Subject test------------" << std::endl;
    int_mstack mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    int_mstack::iterator it = mstack.begin();
    int_mstack::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);
  }

  {
    std::cout << "=operator---------------" << std::endl;
    int_mstack mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    int_mstack mstack_copy;

    mstack_copy = mstack;
    print_stack(mstack_copy);
  }

  {
    std::cout << "Copy Constructor--------" << std::endl;
    int_mstack mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    int_mstack mstack_copy(mstack);
    print_stack(mstack_copy);
  }

  {
    std::cout << "iterator----------------" << std::endl;
    int_mstack mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    for (int_mstack::iterator it = mstack.begin(); it != mstack.end(); it++) {
      std::cout << *it << ", ";
    }
    std::cout << std::endl;
  }

  {
    std::cout << "const iterator----------" << std::endl;
    int_mstack mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    for (int_mstack::const_iterator it = mstack.begin(); it != mstack.end();
         it++) {
      std::cout << *it << ", ";
    }
    std::cout << std::endl;
  }
  {
    std::cout << "reverse iterator--------" << std::endl;
    int_mstack mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    for (int_mstack::reverse_iterator it = mstack.rbegin(); it != mstack.rend();
         it++) {
      std::cout << *it << ", ";
    }
    std::cout << std::endl;
  }

  {
    std::cout << "const reverse iterator--" << std::endl;
    int_mstack mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    for (int_mstack::const_reverse_iterator it = mstack.rbegin();
         it != mstack.rend(); it++) {
      std::cout << *it << ", ";
    }
    std::cout << std::endl;
  }
  return 0;
}