#include <iostream>
using namespace std;


//@brief Swaps two integers by reference.

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//@brief Performs Bubble Sort on the given array.

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}


//@brief Displays the contents of the array.

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Bubble Sort Example" << endl;

    int arr[] = {8, 9, 1, 7, 5, 3, 0, 4, 6, 2, 10};
    int n = sizeof(arr) / sizeof(arr[0]);  

    cout << "Before Bubble Sort: " << endl;
    display(arr, n);  

    bubbleSort(arr, n);  

    cout << "After Bubble Sort: " << endl;
    display(arr, n);  

    return 0;
}
