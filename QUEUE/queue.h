#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "queueADT.h"
using namespace std;

class Queue : public Queue_ADT {
private:
    static const int MAX_SIZE = 10;
    int arr[MAX_SIZE];
    int frontIndex;
    int rearIndex;
    int count; // To keep track of the number of elements in the queue

public:
    Queue() : frontIndex(0), rearIndex(-1), count(0) {}

    void enqueue(int element) override {
        if (isFull()) {
            std::cout << "Queue is full" << std::endl;
        } else {
            rearIndex = (rearIndex + 1) % MAX_SIZE;
            arr[rearIndex] = element;
            count++;
        }
    }

    void dequeue() override {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
        } else {
            frontIndex = (frontIndex + 1) % MAX_SIZE;
            count--;
        }
    }

    int front() const override {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return -1; // Return an error value
        }
        return arr[frontIndex];
    }

    bool isEmpty() const override {
        return count == 0;
    }

    bool isFull() const {
        return count == MAX_SIZE;
    }

    int size() const override {
        return count;
    }
};

#endif
