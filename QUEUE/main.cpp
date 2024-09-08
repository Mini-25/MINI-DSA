#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Front element is: " << q.front() << endl;
    q.dequeue();
    cout << "Front element after dequeue is: " << q.front() << endl;

    return 0;
}
