
# Linear Search Algorithm - Documentation

## 1. Introduction to Linear Search:
Linear Search is the simplest searching algorithm. In this algorithm, we check every element in the array one by one until we either find the target element or exhaust the array. It is effective for small or unsorted datasets but inefficient for large data sets since it needs to examine each element.

## 2. How Linear Search Works:
- Start from the first element of the array.
- Compare the target element (`x`) with each element in the array sequentially.
- If a match is found, return the index of that element.
- If the element is not found after checking all elements, conclude that the element is not present.

---

## 3. Algorithm Explanation:

1. **Input:**
    - An array `arr[]` of size `n`.
    - The element `x` that we need to search for.

2. **Steps:**
    - Start iterating from the first element (index `0`) to the last element (index `n-1`).
    - For each element `arr[i]`, check if it equals the target `x`.
    - If `arr[i] == x`, print the index `i` and terminate the search.
    - If no match is found, after checking all elements, print that the element is not found.

---

## 4. Time and Space Complexity:

- **Time Complexity:**
  - **Best Case:** O(1) – If the element is found at the first position.
  - **Worst Case:** O(n) – If the element is at the last position or not present in the array.
  - **Average Case:** O(n) – On average, we may have to search half the elements.

- **Space Complexity:** O(1) – Only a few additional variables are required regardless of the array size.

---

## 5. Code Implementation:

```cpp
#include<iostream>
using namespace std;

// Function to perform Linear Search
void linearSearch(int arr[], int n, int x) {
    // Iterate through the array
    for(int i = 0; i < n; i++) {
        // Check if the current element is the target element
        if(arr[i] == x) {
            cout << "Element found at index " << i << endl;
            return; // Exit the function after finding the element
        }
    }
    // If the loop completes, element was not found
    cout << "Element not found" << endl;
}

int main() {
    int n;  // Size of the array
    cout << "Enter the size of the array: ";
    cin >> n;  // Input array size

    int arr[n];  // Declare array of size n

    // Input the array elements
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;  // Element to search for
    cout << "Enter the element to be searched: ";
    cin >> x;

    // Call the linearSearch function
    linearSearch(arr, n, x);

    return 0;
}
```

---

## 6. Detailed Explanation of the Code:

1. **Header Section:**
   - `#include<iostream>`: This header file is included to enable input/output operations in the program (e.g., `cin`, `cout`).
   - `using namespace std;`: This allows us to use standard functions like `cout` without prefixing them with `std::`.

2. **Function `linearSearch(int arr[], int n, int x)`**:
   - This function takes three parameters:
     - `arr[]`: The array in which we are searching.
     - `n`: The size of the array.
     - `x`: The element we are trying to find.
   - The function iterates over the array using a `for` loop. If the element `x` is found in the array (`arr[i] == x`), it prints the index where the element was found and exits the function.
   - If the entire array is scanned without finding the element, the function prints "Element not found."

3. **Function `main()`**:
   - First, it prompts the user to enter the size of the array.
   - Then, it collects the array elements from the user.
   - It prompts for the element to be searched and passes these inputs to the `linearSearch` function to perform the search.

---

## 7. Example Run:

**Input:**
```
Enter the size of the array: 5
Enter the elements of the array: 10 20 30 40 50
Enter the element to be searched: 30
```

**Output:**
```
Element found at index 2
```

**Explanation:**
- The array is `[10, 20, 30, 40, 50]`.
- The element `30` is found at index `2` (array indices start from `0`).
- So the function outputs "Element found at index 2".

---

## 8. Pros and Cons of Linear Search:

### Pros:
- Simple to implement and understand.
- No need for sorting the array.
- Works on all types of data (integers, strings, etc.).

### Cons:
- Inefficient for large datasets because it checks every element.
- Slower compared to more advanced algorithms like Binary Search.

---

## 9. When to Use Linear Search:

- **Small datasets**: Linear search is a good choice when the size of the dataset is small.
- **Unsorted data**: It is used when the data is not sorted, and sorting the data may take extra time.
- **Arrays with no constraints**: When the array can contain duplicates or is dynamic in nature.

---

## 10. Conclusion:

Linear search is a straightforward searching technique that can be used when simplicity is prioritized over performance. However, for large datasets, more efficient algorithms such as **Binary Search** are recommended.
