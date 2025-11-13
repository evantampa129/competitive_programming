# Split
Difficulty: 1200  
Source: [Codeforces — Problem 2148E](https://codeforces.com/problemset/problem/2148/E)

This file describes the input/output format for the "Split" problem.

## Problem (summary)
For each test case you are given two integers n and k and an array of n integers. Compute the value required by the problem statement (see the source link above for the exact specification).

## Input
- The first line contains a single integer t — the number of test cases.
- Each test case consists of two lines:
    - The first line contains two integers n and k.
    - The second line contains n integers (the array).

## Output
- For each test case, print a single line with the answer as specified by the problem.

## Algorithmic technique
Typical solutions rely on observation-driven, constructive or greedy approaches combined with counting and prefix/suffix sums. Common building blocks:
- Frequency counting of values.
- Sorting or bucketing (only if needed to order values).
- Linear scans to compute contributions or cumulative sums.
These techniques reduce the problem to a sequence of arithmetic operations and simple updates rather than heavy data structures.

## Time and space complexity
Let n be the length of the array in a single test case.
- **Time (per test case):**
  - O(n) for implementations that use counting and linear scans only.
  - O(n log n) if the solution requires sorting distinct values.
- **Time (overall):** O(sum of n over all test cases) or O(sum n log n) if sorting per test.
- **Space:**
  - O(n) worst-case for frequency maps or auxiliary arrays (often less if values are bounded).

## Example
Input:
```
4
3 2
1 1 1
4 2
1 2 1 2
8 2
3 3 3 3 2 2 2 2
6 3
1 1 1 1 1 1
```

Output:
```
0
7
18
11
```