#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "stackADT.h"
using namespace std;

class stack : public stack_ADT {

private:
    static const int MAX_SIZE = 10;
    int arr[MAX_SIZE];
    int topIndex; 

public:
    stack() : topIndex(-1) {}

    void push(int element) override {
        if (isFull()) {
            std::cout << "Stack is full" << std::endl;
        } else {
            arr[++topIndex] = element;
        }
    }

    void pop() override {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
        } else {
            topIndex--;
        }
    }

    int top() const override {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return -1; // Return an error value
        }
        return arr[topIndex];
    }

    int size() const override {
        return topIndex + 1;
    }

    bool isFull() const {
        return topIndex == MAX_SIZE - 1;
    }

    bool isEmpty() const override {
        return topIndex == -1;
    }
};

#endif
