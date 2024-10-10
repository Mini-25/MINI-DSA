#include<iostream>
using namespace std;

// Function to swap two elements
void swap(int &a, int &b){
    int temp = a; 
    a = b; 
    b = temp;
}

// Partition function that places the pivot in its correct position
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[j]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
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
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    display(arr, size);

    // Perform quick sort
    quickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    display(arr, size);

    return 0;
}