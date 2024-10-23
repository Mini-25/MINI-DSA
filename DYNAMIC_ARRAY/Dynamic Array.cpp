#include <iostream>
using namespace std;

class DynamicArray{
private:
    int* array;
    int capacity, size;

    void resize() {
        int* newArray = new int[capacity * 2];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = capacity * 2;
    }

public:
    DynamicArray() {
        capacity = 1;
        size = 0;
        array = new int[capacity];
    }

    ~DynamicArray() {
        delete[] array;
    }

    void insert(int element){
        if (size == capacity) {
            resize();
        }
        array[size] = element;
        size++;
    }

    void remove() {
        if (size > 0) {
            size--;
        } else {
            cout << "Error: List is empty, cannot remove." << endl;
        }
    }

    void print()  {
        cout << "List: ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    int search(int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return i;
        }
    }
    return -1;  // Element not found
}
};




int main() {
    DynamicArray myList;

    myList.insert(10);
    myList.insert(20);
    myList.insert(30);
    myList.print();
    //List: 10 20 30

    myList.remove();
    myList.print();
    //List: 10 20

    myList.insert(40);
    myList.insert(50);
    myList.print();
    //List: 10 20 40 50

    // Search operations
    int index = myList.search(40);
    if (index != -1) {
        cout << "Element 40 found at index: " << index << endl;
    }
    return 0;
}
