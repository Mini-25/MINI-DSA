#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << "Top element is: " << s.top() << endl;
    s.pop();
    cout << "Top element after pop is: " << s.top() << endl;

    return 0;
}
