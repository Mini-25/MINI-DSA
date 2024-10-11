
# Selection Sort Algorithm

## Overview
Selection Sort is a basic comparison-based algorithm that repeatedly selects the smallest element from the unsorted portion of the array and swaps it with the first element of the unsorted part. This process continues until the entire array is sorted.

**Core Concept**: 
At each step, Selection Sort picks the smallest element from the unsorted section and swaps it with the current element, gradually building up a sorted section at the beginning of the array.

### Why Study This Algorithm?
1. **Simplicity**: Selection Sort is easy to understand and implement, making it a common introduction to sorting algorithms.
2. **In-Place Sorting**: It operates directly on the input array and does not require extra space beyond a few variables.
3. **Deterministic**: The algorithm behaves the same way regardless of the input.

---

## Time and Space Complexity

| Case        | Time Complexity | Space Complexity |
|-------------|-----------------|------------------|
| **Best**    | O(n²)           | O(1) (In-place)  |
| **Average** | O(n²)           | O(1) (In-place)  |
| **Worst**   | O(n²)           | O(1) (In-place)  |

- **Time Complexity**: Selection Sort always performs \(n(n-1)/2\) comparisons, resulting in a time complexity of **O(n²)** in all cases.
- **Space Complexity**: **O(1)** as it only uses a few extra variables and performs in-place sorting.

---

## How It Works

1. **Unsorted Array**: The algorithm treats the entire array as unsorted at the beginning.
2. **Iterative Process**:
   - In each iteration, the algorithm scans the unsorted portion of the array to find the smallest element.
   - The smallest element is swapped with the first element of the unsorted portion.
3. **Sorted Section**: After each iteration, the size of the sorted section increases, and the size of the unsorted section decreases until the entire array is sorted.

---

## Algorithm Workflow

1. **Start from the first element**.
2. **Find the smallest element** in the unsorted part of the array.
3. **Swap** it with the current element (if necessary).
4. **Repeat** this process for each element until the array is sorted.

---

## Detailed Code Explanation

```cpp
#include <iostream>

using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/**
 * @brief Selection Sort Algorithm
 */
void selectionSort(int arr[], int size) {
    // Traverse through all elements in the array
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i; 

        // Find the minimum element in the unsorted portion
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

/**
 * @brief Display the array contents
 */
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 28, 11};  // Example array
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    display(arr, size);  // Display the unsorted array

    // Perform selection sort
    selectionSort(arr, size);

    cout << "Sorted array: ";
    display(arr, size);  // Display the sorted array

    return 0;
}
```

### Code Breakdown
1. **swap() Function**:
   - Swaps two elements by reference.
   - Uses an intermediate variable `temp` to hold one value while the other is swapped.

2. **selectionSort() Function**:
   - Takes the array and its size as input.
   - Iterates through the array, finding the minimum element in each unsorted portion.
   - Swaps the minimum element with the first element of the unsorted portion.
   - Continues until the array is fully sorted.

3. **display() Function**:
   - Prints the elements of the array, useful for displaying the unsorted and sorted arrays before and after sorting.

---

## Example Walkthrough

For an array:  
`{64, 25, 12, 28, 11}`

1. **Iteration 1**:
   - Minimum element is `11`, so `11` and `64` are swapped.
   - Array becomes: `{11, 25, 12, 28, 64}`

2. **Iteration 2**:
   - Minimum element is `12`, so `12` and `25` are swapped.
   - Array becomes: `{11, 12, 25, 28, 64}`

3. **Iteration 3**:
   - Minimum element is `25`, no swap needed.
   - Array remains: `{11, 12, 25, 28, 64}`

4. **Iteration 4**:
   - Minimum element is `28`, no swap needed.
   - Array remains: `{11, 12, 25, 28, 64}`

---

## Best Use Cases of Selection Sort

1. **Small Data Sets**: 
   - Due to its quadratic time complexity, Selection Sort is best suited for small data sets where performance is not a critical concern.

2. **Memory-Constrained Environments**:
   - Since the algorithm sorts in-place without needing additional memory, it is useful in scenarios where memory is limited.

---

## Key Advantages
1. **In-Place Sorting**: Does not require additional memory.
2. **Simplicity**: Straightforward and easy to implement.

---

## Limitations of Selection Sort
1. **Inefficiency for Large Data Sets**: Due to its **O(n²)** time complexity, Selection Sort is inefficient for large data sets.
2. **Lack of Stability**: Selection Sort is not a stable sorting algorithm, meaning that it may change the relative order of equal elements.

---

## Conclusion
Selection Sort is a simple and easy-to-understand sorting algorithm, though it is not the most efficient for large arrays. Its major advantage is that it requires no additional memory beyond the input array, making it ideal for memory-constrained environments. However, for larger data sets or when performance is critical, more advanced algorithms like Merge Sort or Quick Sort should be preferred.
