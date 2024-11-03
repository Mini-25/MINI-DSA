# QuickSort: Complete Step-by-Step
Starting array: `[8, 9, 1, 7, 5, 3, 0, 4, 6, 2, 10]`

## Step 1: First Partition
```
[8, 9, 1, 7, 5, 3, 0, 4, 6, 2, 10]
                              ^^^ Pivot = 10
⬇️ Compare each element with 10
[8, 9, 1, 7, 5, 3, 0, 4, 6, 2 | 10]
Left of |: numbers < 10
Right of |: pivot
```

## Step 2: Left Side Partition
```
[8, 9, 1, 7, 5, 3, 0, 4, 6, 2]
                           ^^^ Pivot = 2

Compare each element with 2:
8 > 2 ➡️ [8]
9 > 2 ➡️ [8, 9]
1 < 2 ➡️ [1, 8, 9]
7 > 2 ➡️ [1, 8, 9, 7]
5 > 2 ➡️ [1, 8, 9, 7, 5]
3 > 2 ➡️ [1, 8, 9, 7, 5, 3]
0 < 2 ➡️ [0, 1, 8, 9, 7, 5, 3]
4 > 2 ➡️ [0, 1, 8, 9, 7, 5, 3, 4]
6 > 2 ➡️ [0, 1, 8, 9, 7, 5, 3, 4, 6]

After rearranging:
[0, 1 | 2 | 8, 9, 7, 5, 3, 4, 6 | 10]
```

## Step 3: Left of 2 ([0, 1])
```
[0, 1]
  ^^^ Pivot = 1

Compare with 1:
0 < 1 ➡️ [0 | 1]

Result: [0, 1, 2 | 8, 9, 7, 5, 3, 4, 6 | 10]
```

## Step 4: Right of 2 ([8, 9, 7, 5, 3, 4, 6])
```
[8, 9, 7, 5, 3, 4, 6]
                  ^^^ Pivot = 6

Compare each element with 6:
8 > 6 ➡️ [8]
9 > 6 ➡️ [8, 9]
7 > 6 ➡️ [8, 9, 7]
5 < 6 ➡️ [5, 8, 9, 7]
3 < 6 ➡️ [5, 3, 8, 9, 7]
4 < 6 ➡️ [5, 3, 4, 8, 9, 7]

After rearranging:
[0, 1, 2 | 3, 4, 5 | 6 | 8, 9, 7 | 10]
```

## Step 5: Left of 6 ([3, 4, 5])
```
[3, 4, 5]
     ^^^ Pivot = 5

Compare with 5:
3 < 5 ➡️ [3]
4 < 5 ➡️ [3, 4 | 5]

Result: [0, 1, 2, 3, 4, 5, 6 | 8, 9, 7 | 10]
```

## Step 6: Right of 6 ([8, 9, 7])
```
[8, 9, 7]
     ^^^ Pivot = 7

Compare with 7:
8 > 7 ➡️ [8]
9 > 7 ➡️ [8, 9]

After rearranging:
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
```

## Final Result
```
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
```

## Visual Flow Summary
```
                [8,9,1,7,5,3,0,4,6,2,10]
                          ↓
        [8,9,1,7,5,3,0,4,6,2] [10]
                  ↓
    [0,1] [2] [8,9,7,5,3,4,6]  [10]
      ↓           ↓
    [0,1]    [3,4,5] [6] [8,9,7]  [10]
      ↓         ↓           ↓
    [0,1]    [3,4,5]    [7,8,9]    [10]
                ↓
[0] [1] [2] [3] [4] [5] [6] [7] [8] [9] [10]
```

Each arrow (⬇️) shows where the algorithm is moving, and each partition creates smaller subgroups that get sorted independently. The vertical bar (|) separates different partitions in the same step.
