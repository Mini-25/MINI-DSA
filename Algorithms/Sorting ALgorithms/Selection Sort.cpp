#include <iostream>

using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to perform Selection Sort
void selectionSort(int arr[], int size) {
    // Traverse the array
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Function to display the array
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 28, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    display(arr, size);

    // Perform selection sort
    selectionSort(arr, size);

    cout << "Sorted array: ";
    display(arr, size);

    return 0;
}
