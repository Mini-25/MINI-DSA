
# Bubble Sort Algorithm - Documentation

## 1. Introduction to Bubble Sort:
Bubble Sort is a simple comparison-based sorting algorithm. It repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process continues until the list is sorted. The algorithm gets its name because smaller elements "bubble" to the top of the list, just like bubbles rising to the surface of water.

## 2. How Bubble Sort Works:
- Bubble Sort compares adjacent elements in the array and swaps them if the first one is larger than the second.
- This process is repeated for every element in the array.
- The algorithm continues to pass through the array until no swaps are needed, which indicates that the array is sorted.
- The algorithm gets progressively more efficient with each pass since the largest unsorted element moves to its correct position after every pass.

---

## 3. Algorithm Explanation:

1. **Input:**
    - An unsorted array `arr[]` of size `n`.

2. **Steps:**
    - Compare adjacent elements.
    - If the first is larger than the second, swap them.
    - Continue doing this for every element.
    - After each pass through the list, the next largest element is in its final position.
    - Continue until the entire list is sorted or no swaps are made during a pass.

---

## 4. Time and Space Complexity:

- **Time Complexity:**
  - **Best Case:** O(n) – When the array is already sorted.
  - **Worst Case:** O(n²) – When the array is sorted in reverse order.
  - **Average Case:** O(n²) – The time complexity in most cases.

- **Space Complexity:** O(1) – Bubble Sort is an in-place sorting algorithm, meaning it does not require additional memory beyond the input array.

---

## 5. Code Implementation:

```cpp
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

        // If no two elements were swapped in the inner loop, the array is sorted
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

    int arr[] = {8, 9, 1, 7, 5, 3, 0, 4, 6, 2, 10};  // Declare and initialize the array
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array

    cout << "Before Bubble Sort: " << endl;
    display(arr, n);  // Display the array before sorting

    bubbleSort(arr, n);  // Perform Bubble Sort on the array

    cout << "After Bubble Sort: " << endl;
    display(arr, n);  // Display the array after sorting

    return 0;
}
```

---

## 6. Detailed Explanation of the Code:

1. **Header Section:**
   - `#include<iostream>`: This header file is needed for input/output operations.
   - `using namespace std;`: Allows us to use standard functions like `cout` without the `std::` prefix.

2. **Function `swap(int &a, int &b)`**:
   - This function swaps two integers by reference. The `&` operator is used to pass the arguments by reference, which means the actual values in memory are swapped.

3. **Function `bubbleSort(int arr[], int n)`**:
   - This function performs Bubble Sort on the array.
   - It uses a nested loop where the outer loop iterates through the array and the inner loop compares adjacent elements.
   - If no elements are swapped during an inner loop pass, it breaks out of the loop, as the array is sorted.

4. **Function `display(int arr[], int n)`**:
   - This function prints the contents of the array.

5. **Function `main()`**:
   - The array is declared and initialized with elements.
   - The size of the array is calculated using `sizeof(arr) / sizeof(arr[0])`.
   - The `display()` function shows the elements of the array before and after sorting.
   - The `bubbleSort()` function is called to sort the array.

---

## 7. Example Run:

**Input:**
```
Before Bubble Sort: 
8 9 1 7 5 3 0 4 6 2 10
```

**Output:**
```
After Bubble Sort:
0 1 2 3 4 5 6 7 8 9 10
```

---

## 8. Pros and Cons of Bubble Sort:

### Pros:
- **Simple to implement**: It is a straightforward algorithm and easy to understand.
- **In-place sorting**: No additional memory is required beyond the input array.

### Cons:
- **Inefficient**: Bubble Sort has poor performance on large datasets due to its O(n²) time complexity.
- **Rarely used**: It is not practical for sorting large datasets, and more efficient algorithms like Quick Sort or Merge Sort are preferred.

---

## 9. When to Use Bubble Sort:

- **Small datasets**: Bubble Sort is acceptable when dealing with small datasets.
- **Teaching purposes**: It is often used as a teaching tool to introduce sorting concepts.

---

## 10. Conclusion:

Bubble Sort is a simple but inefficient sorting algorithm. Although it is not used for large datasets due to its O(n²) time complexity, it is useful for educational purposes and for understanding the basic principles of sorting algorithms.
