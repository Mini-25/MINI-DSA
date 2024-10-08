
# Insertion Sort Algorithm - Documentation

## 1. Introduction to Insertion Sort:
Insertion Sort is a comparison-based algorithm where each element in the array is placed in its correct position relative to previously sorted elements. It works similarly to how people sort playing cards by picking one card at a time and placing it in the correct position.

## 2. How Insertion Sort Works:
- The array is divided into two parts: sorted and unsorted.
- The algorithm picks elements one by one from the unsorted part and places them in the correct position in the sorted part.
- This continues until the whole array is sorted.

---

## 3. Algorithm Explanation:

1. **Input:**
    - An unsorted array `arr[]` of size `n`.

2. **Steps:**
    - Start from the second element, treating the first element as a sorted sublist.
    - Compare the current element (key) with the elements of the sorted sublist.
    - Shift the larger elements to the right to make space for the key.
    - Place the key in its correct position.
    - Repeat for all elements until the array is sorted.

---

## 4. Time and Space Complexity:

- **Time Complexity:**
  - **Best Case:** O(n) – When the array is already sorted.
  - **Worst Case:** O(n²) – When the array is sorted in reverse order.
  - **Average Case:** O(n²) – In most scenarios.

- **Space Complexity:** O(1) – Insertion Sort is an in-place sorting algorithm, meaning it uses only a constant amount of additional memory.

---

## 5. Code Implementation:

```cpp
#include <iostream>
using namespace std;

//@brief Performs Insertion Sort on the given array.
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements that are greater than key, one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;  // Place the key in the correct position
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
    cout << "Insertion Sort Example" << endl;

    // Example array
    int arr[] = {8, 9, 1, 7, 5, 3, 0, 4, 6, 2, 10};  // Declare and initialize the array
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array

    cout << "Before Insertion Sort: " << endl;
    display(arr, n);  // Display the array before sorting

    insertionSort(arr, n);  // Perform Insertion Sort on the array

    cout << "After Insertion Sort: " << endl;
    display(arr, n);  // Display the array after sorting

    return 0;
}
```

---

## 6. Detailed Explanation of the Code:

1. **Header Section:**
   - `#include<iostream>`: This header file is needed for input/output operations.
   - `using namespace std;`: Allows us to use standard functions like `cout` without the `std::` prefix.

2. **Function `insertionSort(int arr[], int n)`**:
   - This function performs Insertion Sort on the array.
   - The outer loop iterates through the array starting from the second element.
   - The inner `while` loop compares the current element (key) with the elements in the sorted part of the array and shifts larger elements to the right.

3. **Function `display(int arr[], int n)`**:
   - This function prints the contents of the array.

4. **Function `main()`**:
   - The array is declared and initialized with elements.
   - The size of the array is calculated using `sizeof(arr) / sizeof(arr[0])`.
   - The `display()` function shows the elements of the array before and after sorting.
   - The `insertionSort()` function is called to sort the array.

---

## 7. Example Run:

**Input:**
```
Before Insertion Sort: 
8 9 1 7 5 3 0 4 6 2 10
```

**Output:**
```
After Insertion Sort:
0 1 2 3 4 5 6 7 8 9 10
```

---

## 8. Pros and Cons of Insertion Sort:

### Pros:
- **Simple to implement**: Insertion Sort is easy to implement and understand.
- **Efficient for small datasets**: It performs well with small or nearly sorted datasets.
- **Stable sort**: Insertion Sort maintains the relative order of equal elements.

### Cons:
- **Inefficient for large datasets**: Its O(n²) time complexity makes it impractical for large datasets.

---

## 9. When to Use Insertion Sort:

- **Small datasets**: Insertion Sort is suitable for small datasets or lists that are already partially sorted.
- **Nearly sorted data**: It is efficient when the input array is nearly sorted.

---

## 10. Conclusion:

Insertion Sort is a straightforward algorithm that works well for small or nearly sorted datasets. Although it is not efficient for large datasets due to its O(n²) time complexity, it is commonly used in teaching and for small-scale applications.
