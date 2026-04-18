// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template <typename T, int size> class TStack {
private:
  T arr[size];
  int top_index;

public:
  TStack() : top_index(-1) {}

  bool isEmpty() const { return top_index == -1; }

  bool isFull() const { return top_index == size - 1; }

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
