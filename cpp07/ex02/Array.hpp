#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
 public:
  Array();
  Array(unsigned int len);
  Array(Array const& src);
  ~Array();

  T& operator[](unsigned int n);
  Array& operator=(Array const& rhs);

  unsigned int size() const;

 private:
  T* value_;
  unsigned int size_;
};

template <typename T>
Array<T>::Array() {
  value_ = new T[0]();
  size_ = 0;
}

template <typename T>
Array<T>::Array(unsigned int len) {
  value_ = new T[len]();
  size_ = len;
}

template <typename T>
Array<T>::Array(Array const& src) {
  this->value_ = NULL;
  *this = src;
}

template <typename T>
Array<T>::~Array() {
  delete[] value_;
}

template <typename T>
T& Array<T>::operator[](unsigned int n) {
  if (n >= size_) {
    throw std::exception();
  }
  return value_[n];
}

template <typename T>
unsigned int Array<T>::size() const {
  return size_;
}

template <typename T>
Array<T>& Array<T>::operator=(Array const& rhs) {
  if (this != &rhs) {
    delete[] this->value_;
    this->value_ = new T[rhs.size_]();
    for (size_t i = 0; i < rhs.size_; i++) {
      this->value_[i] = rhs.value_[i];
    }
    this->size_ = rhs.size_;
  }
  return *this;
}

#endif