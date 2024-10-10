
# Quick Sort Algorithm - Documentation

## 1. Introduction to Quick Sort:
Quick Sort is an efficient, divide-and-conquer sorting algorithm that picks a pivot element and partitions the array into two halves: elements smaller than the pivot go to the left, and elements greater go to the right. The algorithm then recursively sorts the sub-arrays.

## 2. How Quick Sort Works:
- Select a **pivot** element from the array (commonly the last element).
- Partition the array such that elements smaller than the pivot move to the left, and larger elements move to the right.
- Recursively apply the same process to the sub-arrays formed by the pivot.

---

## 3. Algorithm Explanation:

1. **Input:**
    - An unsorted array `arr[]` of size `n`.

2. **Steps:**
    - Choose a pivot element (commonly the last element).
    - Partition the array: elements smaller than the pivot are moved to the left, and elements greater than the pivot are moved to the right.
    - Recursively apply the Quick Sort algorithm to the sub-arrays on the left and right of the pivot.
    - The process continues until the entire array is sorted.

---

## 4. Time and Space Complexity:

- **Time Complexity:**
  - **Best Case:** O(n log n) – When the pivot divides the array into balanced sub-arrays.
  - **Worst Case:** O(n²) – When the pivot divides the array into highly unbalanced sub-arrays (e.g., when the array is already sorted).
  - **Average Case:** O(n log n).

- **Space Complexity:** O(log n) – Due to recursive function calls on the stack.

---

## 5. Code Implementation:

```cpp
#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function that places the pivot in its correct position
// and arranges smaller elements to the left and larger elements to the right
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choosing the last element as pivot
    int i = low - 1;        // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;  // Increment index of the smaller element
            swap(arr[i], arr[j]);
        }
    }
    // Swap the pivot element with the element at i+1
    swap(arr[i + 1], arr[high]);
    return (i + 1);  // Return the partitioning index
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after the partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
```

---

## 6. Detailed Explanation of the Code:

1. **Header Section:**
   - `#include<iostream>`: Required for input/output operations.
   - `using namespace std;`: Allows us to use `cout` and other standard library functions.

2. **Function `swap(int &a, int &b)`**:
   - This function swaps two elements in the array using references.

3. **Function `partition(int arr[], int low, int high)`**:
   - This function partitions the array around the pivot.
   - Elements smaller than the pivot are placed to the left, and larger elements are placed to the right.
   - The pivot is swapped into its correct position, and its index is returned.

4. **Function `quickSort(int arr[], int low, int high)`**:
   - The main Quick Sort function. It recursively partitions and sorts the sub-arrays.
   - The base condition `if (low < high)` ensures that sorting is performed only when the array has more than one element.

5. **Function `display(int arr[], int size)`**:
   - This function prints the contents of the array.

6. **Function `main()`**:
   - The array is declared and initialized.
   - The size of the array is determined using `sizeof(arr) / sizeof(arr[0])`.
   - The `display()` function shows the elements before and after sorting.
   - The `quickSort()` function is called to sort the array.

---

## 7. Example Run:

**Input:**
```
Unsorted array: 10 7 8 9 1 5
```

**Output:**
```
Sorted array: 1 5 7 8 9 10
```

---

## 8. Pros and Cons of Quick Sort:

### Pros:
- **Efficient**: Quick Sort has an average time complexity of O(n log n), making it faster than algorithms like Bubble Sort and Insertion Sort.
- **In-place sorting**: It uses constant extra memory for sorting.

### Cons:
- **Worst-case time complexity**: In the worst case (when the pivot divides the array unevenly), the time complexity becomes O(n²).
- **Recursive**: Quick Sort uses recursion, which could lead to stack overflow on large arrays.

---

## 9. When to Use Quick Sort:

- **Large datasets**: Quick Sort is efficient for sorting large datasets due to its average-case time complexity of O(n log n).
- **Arrays**: It is particularly suited for arrays, where elements need to be sorted in place.

---

## 10. Conclusion:

Quick Sort is a widely-used sorting algorithm due to its efficiency and in-place sorting capabilities. It is ideal for large datasets but can suffer from poor performance in the worst-case scenario. Proper pivot selection can help mitigate the risk of worst-case performance.
