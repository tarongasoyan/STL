#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <iostream>
// #include "stack.cpp"

template <typename T>
class Stack {
private:
	struct Node{
		T data;
		Node* next;
	};
	Node* top;
	int m_size;
	int m_count;
public:
	Stack();
	Stack(int size);
	Stack(const Stack& other);
	Stack(Stack&& other) noexcept;
	~Stack();
public:
	void push(T item);
	T pop();
	T peek() const;
	bool isEmpty() const;
	bool isFull() const;
	int size() const;
	int count() const;
	void printStack() const;
	void change(T item);
	Stack& operator=(const Stack& other);
};

#endif //STACK_H
