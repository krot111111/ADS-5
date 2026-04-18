// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

#include <stdexcept>

template <typename T, int kSize> class TStack {
 private:
  T arr[kSize];
  int top_index;

public:
  TStack() : top_index(-1) {}

  bool isEmpty() const { return top_index == -1; }

  bool isFull() const { return top_index == kSize - 1; }

  void push(const T &item) {
    if (isFull()) {
      throw std::out_of_range("Stack overflow");
    }
    arr[++top_index] = item;
  }

  T pop() {
    if (isEmpty()) {
      throw std::out_of_range("Stack underflow");
    }
    return arr[top_index--];
  }

  T get() const {
    if (isEmpty()) {
      throw std::out_of_range("Stack underflow");
    }
    return arr[top_index];
  }
};

#endif // INCLUDE_TSTACK_H_
