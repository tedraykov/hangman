#ifndef VECTOR_H
#define VECTOR_H
#include "Word.h"
#include <stdexcept>
#include <iostream>

template<typename T>
class Vector {
public:
    Vector();
    virtual ~Vector();
    unsigned int size();
    void resize();
    bool isEmpty();
    void push(T a);
    T pop();
    T& operator[](unsigned int i);
private:
    T* arr;
    unsigned int n;
    unsigned int capacity;
};


template<typename T>
Vector<T>::Vector() {
    n = 0;
    capacity = 1;
    arr = new T[capacity];
}

template<typename T>
Vector<T>::~Vector() {
    delete[] arr;
}

template<typename T>
unsigned int Vector<T>::size() { return n; }

template<typename T>
bool Vector<T>::isEmpty() { return size() == 0; }

template<typename T>
void Vector<T>::resize() {
    if ( 2 * n < capacity) capacity /= 2;
    else                   capacity *= 2;

    auto __arr = new T[capacity];

    for (unsigned int i = 0; i < n; i++)
        __arr[i] = arr[i];

    if (arr != nullptr) delete[] arr;

    arr = __arr;
}

template<typename T>
void Vector<T>::push(T a) {
    if (size() >= capacity) resize();
    arr[n] = a;
    ++n;
}

template<typename T>
T Vector<T>::pop() {
    if (isEmpty()) throw std::exception("Cannot remove from empty array");
    else {
        n--;
        if (2 * n < capacity) resize();
        return arr[n];
    }
}

template<typename T>
T& Vector<T>::operator[](unsigned int i) {
    if (i >= n) std::cout << "Out of bound exception";
    return arr[i];
}

#endif // VECTOR_H
