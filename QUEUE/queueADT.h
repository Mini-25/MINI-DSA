#ifndef QUEUE_ADT_H
#define QUEUE_ADT_H

class Queue_ADT {
public:
    virtual void enqueue(int element) = 0;
    virtual void dequeue() = 0;
    virtual int front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual int size() const = 0;
};
#endif
