#include <iostream>
using namespace std;

//@brief Performs Insertion Sort on the given array.

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


//@brief Displays the contents of the array.
 
void display(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Insertion Sort Example" << endl;

    // Example array
    int arr[] = {8, 9, 1, 7, 5, 3, 0, 4, 6, 2, 10};
    int n = sizeof(arr) / sizeof(arr[0]);  

    cout << "Before Insertion Sort: " << endl;
    display(arr, n);  

    insertionSort(arr, n);  

    cout << "After Insertion Sort: " << endl;
    display(arr, n);  

    return 0;
}