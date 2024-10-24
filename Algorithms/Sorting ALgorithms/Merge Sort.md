# Merge Sort Implementation Documentation

## Table of Contents
1. [Code Overview](#code-overview)
2. [Implementation Details](#implementation-details)
3. [Function Analysis](#function-analysis)
4. [Visual Example Walkthrough](#visual-example-walkthrough)
5. [Main Program Analysis](#main-program-analysis)
6. [Output Analysis](#output-analysis)
7. [Example Scenarios](#example-scenarios)
8. [Best Practices](#best-practices)
9. [Complexity Analysis](#complexity-analysis)

## 1. Code Overview

### Purpose
This implementation provides a merge sort algorithm that sorts an array by recursively dividing it into smaller subarrays, sorting them, and then merging them back together in sorted order.

### Features
- Divide-and-conquer approach
- Stable sorting algorithm
- In-place merging
- Array visualization
- Recursive implementation

## 2. Implementation Details

### Function Signatures
```cpp
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);
void display(int arr[], int size);
```

### Core Components:
1. `mergeSort`: Main recursive function
2. `merge`: Combines sorted subarrays
3. `display`: Visualization helper

## 3. Function Analysis

### Merge Function
```cpp
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    int leftArr[n1], rightArr[n2];
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
        
    // Merge process
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements
    while (i < n1) {
        arr[k] = leftArr[i];
        i++; k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++; k++;
    }
}
```

#### Algorithm Steps:
1. Calculate sizes of subarrays
2. Create temporary arrays
3. Copy data to temporary arrays
4. Merge back while maintaining order
5. Handle remaining elements

### MergeSort Function
```cpp
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
```

#### Process:
1. Check if subdivision needed
2. Calculate middle point
3. Recursively sort left half
4. Recursively sort right half
5. Merge sorted halves

## 4. Visual Example Walkthrough

Let's walk through sorting the array: [12, 11, 13, 5, 6, 7]

### Step 1: Initial Division
```
                [12, 11, 13, 5, 6, 7]
                /                    \
        [12, 11, 13]             [5, 6, 7]
        /          \             /        \
    [12]       [11, 13]       [5]      [6, 7]
```

### Step 2: Further Division and Initial Merging
```
    [12]       [11] [13]      [5]      [6] [7]
      \         /    |         |        /    |
    [12]    [11, 13]          [5]    [6, 7]
```

### Step 3: First Level Merging
```
    [12]    [11, 13]          [5]    [6, 7]
       \    /                    \    /
   [11, 12, 13]              [5, 6, 7]
```

### Step 4: Final Merge
```
        [11, 12, 13]        [5, 6, 7]
                \            /
          [5, 6, 7, 11, 12, 13]
```

## 5. Main Program Analysis

```cpp
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Unsorted array: ";
    display(arr, size);
    
    mergeSort(arr, 0, size - 1);
    
    cout << "Sorted array: ";
    display(arr, size);
    
    return 0;
}
```

## 6. Output Analysis

Sample Output:
```
Unsorted array: 12 11 13 5 6 7
Sorted array: 5 6 7 11 12 13
```

## 7. Example Scenarios

### Scenario 1: Already Sorted Array
```cpp
int arr[] = {1, 2, 3, 4, 5};
// Still divides and merges, but no reordering needed
```

### Scenario 2: Reverse Sorted Array
```cpp
int arr[] = {5, 4, 3, 2, 1};
// Maximum reordering required
```

### Scenario 3: Array with Duplicates
```cpp
int arr[] = {3, 1, 3, 2, 1};
// Maintains stability for equal elements
```

## 8. Best Practices

1. **Memory Efficiency**
   - Use dynamic allocation for large arrays
   - Consider in-place merging for space optimization
   - Implement iterative version for stack efficiency

2. **Optimization Techniques**
   - Use insertion sort for small subarrays
   - Optimize temporary array allocation
   - Consider parallel implementation for large datasets

## 9. Complexity Analysis

### Time Complexity
| Case    | Complexity |
|---------|------------|
| Best    | O(n log n) |
| Average | O(n log n) |
| Worst   | O(n log n) |

### Space Complexity
- Additional Space: O(n)
- Recursive Stack: O(log n)

### Detailed Analysis
1. **Dividing Stage**
   - Log n levels of recursion
   - Each level splits array in half

2. **Merging Stage**
   - n elements processed at each level
   - Total n * log n operations

3. **Memory Usage**
   - Temporary arrays: O(n)
   - Stack frames: O(log n)
   - Total: O(n)

### Performance Characteristics
- Stable sort
- Not in-place
- Predictable performance
- Cache-friendly sequential access

The merge sort algorithm maintains consistent O(n log n) performance regardless of input data, making it reliable for large datasets where predictable performance is crucial.
