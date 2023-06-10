#ifndef STACK_H
#define STACK_H
#include <iostream>

template <class T>
class Stack {
 public:
  Stack(int size);
  ~Stack();
  void push(T value);
  T pop();
  T peek();
  bool isEmpty() const;
  T getTop() const;
  void invert();

  T* array;

 private:
  int capacity;
  int top;
};

template <class T>
Stack<T>::Stack(int size) : capacity(size), top(-1) {
  array = new T[capacity];
}

template <class T>
Stack<T>::~Stack() {
  delete[] array;
}

template <class T>
void Stack<T>::push(T value) {
  if (top == capacity - 1) {
    std::cout << "Stack overflow" << std::endl;
    return;
  }
  array[++top] = value;
}

template <class T>
T Stack<T>::pop() {
  if (top == -1) {
    std::cout << "Stack underflow" << std::endl;
    return T();
  }
  return array[top--];
}

template <class T>
T Stack<T>::peek() {
  if (top == -1) {
    std::cout << "Stack is empty" << std::endl;
    return T();
  }
  return array[top];
}

template <class T>
bool Stack<T>::isEmpty() const {
  return top == -1;
}

template <class T>
T Stack<T>::getTop() const {
  return this->array[top];
}

template <class T>
void Stack<T>::invert() {
  if (this->isEmpty()) {
    return;  // No need to invert an empty stack
  }

  int size = top + 1;
  for (int i = 0; i < size / 2; i++) {
    // Swap elements from top to bottom
    T temp = this->array[i];
    this->array[i] = this->array[size - i - 1];
    this->array[size - i - 1] = temp;
  }
}

#endif  // STACK_H

