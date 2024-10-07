
# Binary Search Algorithm - Documentation

## 1. Introduction to Binary Search:
Binary Search is an efficient algorithm used to find the position of a target element in a sorted array. Unlike linear search, which checks each element one by one, binary search works by repeatedly dividing the array in half, thus reducing the search space by half at each step. It is significantly faster than linear search, especially for large datasets.

## 2. How Binary Search Works:
- The array must be **sorted** before applying binary search.
- Start with two pointers, one pointing to the beginning (`start`) and the other pointing to the end (`end`) of the array.
- Calculate the middle element index (`mid`) as `mid = start + (end - start)/2`.
- Compare the middle element with the target (`x`):
  - If `arr[mid] == x`, the target element is found at the `mid` index.
  - If `arr[mid] > x`, discard the right half of the array (`end = mid - 1`).
  - If `arr[mid] < x`, discard the left half of the array (`start = mid + 1`).
- Repeat the process until the element is found or the search space becomes empty (i.e., `start > end`).

---

## 3. Algorithm Explanation:

1. **Input:**
    - A sorted array `arr[]` of size `n`.
    - The target element `x` that we need to search.

2. **Steps:**
    - Initialize `start` to 0 and `end` to `n-1`.
    - Calculate `mid` as the middle of the current subarray.
    - Compare `arr[mid]` with `x`:
      - If `arr[mid] == x`, return the index `mid`.
      - If `arr[mid] > x`, narrow the search to the left half by setting `end = mid - 1`.
      - If `arr[mid] < x`, narrow the search to the right half by setting `start = mid + 1`.
    - If the element is not found by the time the `start` exceeds `end`, return "Element not found."

---

## 4. Time and Space Complexity:

- **Time Complexity:**
  - **Best Case:** O(1) – When the element is found at the middle.
  - **Worst Case:** O(log n) – The search space is reduced by half in every iteration.
  - **Average Case:** O(log n).

- **Space Complexity:** O(1) – The algorithm uses a constant amount of extra space.

---

## 5. Code Implementation:

```cpp
#include<iostream>
using namespace std;

// Function to perform Binary Search
void binarySearch(int arr[], int n, int x) {
    int start = 0;  // Initialize start index
    int end = n - 1;  // Initialize end index

    // Continue the loop as long as the search space is valid
    while (start <= end) {
        int mid = start + (end - start) / 2;  // Calculate middle index

        // If the target is found at mid, print its index and return
        if (arr[mid] == x) {
            cout << "Element found at index " << mid << endl;
            return;
        }
        // If the target is smaller, ignore the right half
        else if (arr[mid] > x) {
            end = mid - 1;
        }
        // If the target is larger, ignore the left half
        else {
            start = mid + 1;
        }
    }
    // If we exit the loop, the element was not found
    cout << "Element not found" << endl;
}

int main() {
    int n;  // Size of the array
    cout << "Enter the size of the array: ";
    cin >> n;  // Input array size

    int arr[n];  // Declare an array of size n

    // Input the array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;  // Element to search for
    cout << "Enter the element to be searched: ";
    cin >> x;

    // Call the binarySearch function
    binarySearch(arr, n, x);

    return 0;
}
```

---

## 6. Detailed Explanation of the Code:

1. **Header Section:**
   - `#include<iostream>`: This header file is required for input/output operations (like `cin`, `cout`).
   - `using namespace std;`: This allows us to use standard functions like `cout` directly without using the `std::` prefix.

2. **Function `binarySearch(int arr[], int n, int x)`**:
   - This function takes three parameters:
     - `arr[]`: The sorted array in which we are searching.
     - `n`: The size of the array.
     - `x`: The element to find.
   - We initialize two pointers: `start` (initially 0) and `end` (initially `n-1`), which represent the current search space.
   - The loop continues until `start <= end`.
   - In each iteration, we calculate the middle index `mid`, check if the middle element is the target, and adjust the search range accordingly.
   - If the element is not found by the end of the loop, the function prints "Element not found."

3. **Function `main()`**:
   - First, it prompts the user to enter the size of the array.
   - Then, it collects the array elements from the user.
   - Finally, it prompts for the element to be searched and passes the inputs to the `binarySearch` function to perform the search.

---

## 7. Example Run:

**Input:**
```
Enter the size of the array: 6
Enter the elements of the array: 5 10 15 20 25 30
Enter the element to be searched: 20
```

**Output:**
```
Element found at index 3
```

**Explanation:**
- The array is `[5, 10, 15, 20, 25, 30]`.
- The element `20` is found at index `3` (array indices start from `0`).
- So, the function outputs "Element found at index 3".

---

## 8. Pros and Cons of Binary Search:

### Pros:
- **Fast**: Much faster than linear search, especially for large datasets (O(log n)).
- **Efficient**: Reduces the search space by half in every step.

### Cons:
- **Requires a sorted array**: The array must be sorted before performing binary search.
- **Less efficient for small datasets**: For very small datasets, linear search may be more practical due to its simplicity.

---

## 9. When to Use Binary Search:

- **Sorted datasets**: Binary search is highly efficient when dealing with large, sorted datasets.
- **Frequent searches**: When performing multiple searches on the same data, sorting the data once and using binary search can save a lot of time.

---

## 10. Conclusion:

Binary search is a powerful search algorithm that outperforms linear search for large, sorted datasets. It is an essential algorithm in computer science due to its logarithmic time complexity.
