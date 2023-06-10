#include "stack.h"

template <typename T>
Stack<T>::Stack() : top(nullptr), m_size(0), m_count(0) {}

template <typename T>
Stack<T>::Stack(int size) : top(nullptr), m_size(m_size), m_count(0) {}

template <typename T>
Stack<T>::Stack(const Stack& other) : top(nullptr), m_size(other.m_size), m_count(other.m_count) {
    if (other.top == nullptr) {
        top = nullptr;
    } else {
        Node* current = other.top;
        Node* temp = new Node;
        temp->data = current->data;
        temp->next = nullptr;
        top = temp;

        current = current->next;

        while (current != nullptr) {
            Node* newNode = new Node;
            newNode->data = current->data;
            newNode->next = top;
            top = newNode;
            current = current->next;
        }
    }
}

template <typename T>
Stack<T>::Stack(Stack&& other) noexcept : top(nullptr), m_size(0), m_count(0) {
    std::swap(top, other.top_);
    std::swap(m_size, other.size_);
    std::swap(m_count, other.count_);
}

template <typename T>
Stack<T>::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
void Stack<T>::push(T item) {
    if (isFull()) {
        throw std::overflow_error("Stack is full.");
    }
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = top;
    top = newNode;
    ++m_count;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty.");
    }
    T item = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    --m_count;
    return item;
}

template <typename T>
T Stack<T>::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty.");
    }
    return top->data;
}

template <typename T>
void Stack<T>::change(T item) {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty.");
    }
    top->data = item;
}

template <typename T>
int Stack<T>::count() const {
    return m_count;
}

template <typename T>
int Stack<T>::size() const {
    return m_size;   
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return m_count == 0;
}

template <typename T>
bool Stack<T>::isFull() const {
    return m_size > 0 && m_count == m_size;
}

template <typename T>
void Stack<T>::printStack() const {
    if (isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        Node* current = top;
        std::cout << "Stack: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if (this != &other) {
        Stack temp(other);
        std::swap(top, temp.top);
        std::swap(m_size, temp.m_size);
        std::swap(m_count, temp.m_count);
    }
    return *this;
}


