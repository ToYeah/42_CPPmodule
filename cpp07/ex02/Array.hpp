#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
 public:
  Array();
  Array(const unsigned int& len);
  Array(const Array& src);
  ~Array();

  T& operator[](const unsigned int& n) const;
  Array& operator=(const Array& rhs);

  unsigned int size() const;

 private:
  T* value_;
  unsigned int size_;
};

template <typename T>
Array<T>::Array() : value_(NULL), size_(0) {
  value_ = new T[size_]();
}

template <typename T>
Array<T>::Array(const unsigned int& len) : value_(NULL), size_(len) {
  value_ = new T[size_]();
}

template <typename T>
Array<T>::Array(const Array& src) : value_(NULL), size_(0) {
  *this = src;
}

template <typename T>
Array<T>::~Array() {
  delete[] value_;
}

template <typename T>
T& Array<T>::operator[](const unsigned int& index) const {
  if (index >= size_) {
    throw std::out_of_range("Invalid Index");
  }
  return value_[index];
}

template <typename T>
unsigned int Array<T>::size() const {
  return size_;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs) {
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