#ifndef STACK_ADT_H
#define STACK_ADT_H

class stack_ADT{
    public:
        virtual void push(int element) = 0; 
        virtual void pop() = 0;
        virtual int top() const = 0; 
        virtual bool isEmpty() const = 0;
        virtual int size() const = 0;
};
#endif
