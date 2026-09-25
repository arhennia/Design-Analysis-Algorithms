# Design & Analysis of Algorithms (DAAL)

A structured collection of C implementations exploring fundamental algorithms, data structures, and problem-solving techniques.

This repository documents hands-on lab implementations covering array manipulation, recursion, divide and conquer, heaps, greedy algorithms, graph algorithms, and dynamic programming.

> **Language:** C  
> **Compiler:** GCC  
> **Guide:** [GUIDE.md](file:///c:/Users/KIIT/DAAL/GUIDE.md)

---

## Repository Overview

The repository covers core algorithm design paradigms:

- **Arrays & Frequency Analysis** (Day 1)
- **Recursion & File I/O** (Day 2)
- **Divide and Conquer** (Day 3)
- **Heaps & Priority Queues** (Day 4)
- **Greedy Techniques — Part I** (Day 5)
- **Greedy Techniques — Part II (MST)** (Day 6)
- **Greedy Techniques — Part III (Shortest Path)** (Day 7)
- **Dynamic Programming** (Day 8)
- Backtracking *(coming soon)*

---

## Lab Progress & Programs

### Day 1: Arrays

| # | Program | Description |
|---|---------|-------------|
| 1.1 | [`second_smallest_largest.c`](day-1/second_smallest_largest.c) | Find the second smallest and second largest elements in an array |
| 1.2 | [`prefix_sum.c`](day-1/prefix_sum.c) | Compute prefix sums of an array |
| 1.3 | [`duplicate_count.c`](day-1/duplicate_count.c) | Count duplicates and determine the most frequent element |
| 1.4 | [`rotate_array.c`](day-1/rotate_array.c) | Rotate an array to the right by *k* positions |

---

### Day 2: Recursion & File I/O

| # | Program | Description |
|---|---------|-------------|
| 2.1 | [`decimal_to_binary.c`](day-2/decimal_to_binary.c) | Convert decimal numbers to binary using recursion and file streams |
| 2.2 | [`gcd_recursive.c`](day-2/gcd_recursive.c) | Compute GCD using recursive Euclidean Algorithm from file input |

---

### Day 3: Divide and Conquer

| # | Program | Description |
|---|---------|-------------|
| 3.1 | [`merge_sort.c`](day-3/merge_sort.c) | Sort an array in $O(n \log n)$ time using Divide and Conquer Merge Sort |
| 3.2 | [`quick_sort.c`](day-3/quick_sort.c) | Partition-based in-place sorting using Quick Sort |

---

### Day 4: Heaps & Priority Queues

| # | Program | Description |
|---|---------|-------------|
| 4.1 | [`person_heap.c`](day-4/person_heap.c) | Menu-driven program managing dynamic `struct person` records with Min-Heap (age), Max-Heap (weight), insertion, and deletion |

**Menu Features:**
1. Read student data from file into dynamically allocated `struct person` array
2. Create Min-heap based on age
3. Create Max-heap based on weight
4. Display weight of youngest student (converted to kg)
5. Insert new person into Min-heap
6. Delete the oldest person while preserving heap property

---

### Day 5: Greedy Techniques

| # | Program | Description |
|---|---------|-------------|
| 5.1 | [`fractional_knapsack.c`](day-5/fractional_knapsack.c) | Fractional Knapsack maximizing profit using Heap Sort on profit/weight ratio |
| 5.2 | [`huffman_coding.c`](day-5/huffman_coding.c) | Construct Huffman Tree using Min-Priority Queue and output in-order traversal |

---

### Day 6: Minimum Cost Spanning Tree (Greedy)

| # | Program | Description |
|---|---------|-------------|
| 6.1 | [`prims_mst.c`](day-6/prims_mst.c) | Prim's Algorithm using Min-Priority Queue on cost adjacency matrix to find MST and total cost |
| 6.2 | [`kruskals_mst.c`](day-6/kruskals_mst.c) | Kruskal's Algorithm using Disjoint Set Union (DSU) to find MST edges and total cost |

---

### Day 7: Single Source Shortest Path (Greedy)

| # | Program | Description |
|---|---------|-------------|
| 7.1 | [`dijkstras_algorithm.c`](day-7/dijkstras_algorithm.c) | Dijkstra's Algorithm on directed graph to compute shortest path lengths and paths from source |

---

### Day 8: Dynamic Programming

| # | Program | Description |
|---|---------|-------------|
| 8.1 | [`matrix_chain_multiplication.c`](day-8/matrix_chain_multiplication.c) | Matrix Chain Multiplication computing M-table, S-table, optimal parenthesization, and scalar multiplications |
| 8.2 | [`longest_common_subsequence.c`](day-8/longest_common_subsequence.c) | Longest Common Subsequence (LCS) using DP table to find LCS string and length |

---

## Repository Structure

```text
DAAL/
├── .gitignore
├── GUIDE.md
├── README.md
│
├── day-1/
│   ├── duplicate_count.c
│   ├── prefix_sum.c
│   ├── rotate_array.c
│   ├── second_smallest_largest.c
│   └── input/
│       ├── input.txt
│       ├── input1.txt
│       └── input2.txt
│
├── day-2/
│   ├── decimal_to_binary.c
│   ├── decimal_to_binary.txt
│   ├── gcd_recursive.c
│   ├── gcd_recursive.txt
│   └── data/
│       ├── inDec.dat
│       ├── inGcd.dat
│       ├── outBin.dat
│       └── outGcd.dat
│
├── day-3/
│   ├── merge_sort.c
│   ├── merge_sort.txt
│   ├── quick_sort.c
│   └── quick_sort.txt
│
├── day-4/
│   ├── person_heap.c
│   ├── person_heap.txt
│   └── input/
│       └── students.txt
│
├── day-5/
│   ├── fractional_knapsack.c
│   ├── fractional_knapsack.txt
│   ├── huffman_coding.c
│   └── huffman_coding.txt
│
├── day-6/
│   ├── kruskals_mst.c
│   ├── kruskals_mst.txt
│   ├── prims_mst.c
│   ├── prims_mst.txt
│   └── input/
│       ├── inUnAdjMat.dat
│       └── kruskal_input.txt
│
├── day-7/
│   ├── dijkstras_algorithm.c
│   ├── dijkstras_algorithm.txt
│   └── input/
│       └── inDiAdjMat1.dat
│
└── day-8/
    ├── longest_common_subsequence.c
    ├── longest_common_subsequence.txt
    ├── matrix_chain_multiplication.c
    ├── matrix_chain_multiplication.txt
    └── input/
        ├── lcs_input.txt
        └── mcm_input.txt
```

---

## Compilation & Execution

Compile using GCC:

### Day 6 Examples (MST)
```bash
cd day-6

# Prim's Algorithm
gcc -Wall -Wextra prims_mst.c -o prims_mst
./prims_mst

# Kruskal's Algorithm
gcc -Wall -Wextra kruskals_mst.c -o kruskals_mst
./kruskals_mst < input/kruskal_input.txt
```

### Day 7 Example (Dijkstra)
```bash
cd day-7
gcc -Wall -Wextra dijkstras_algorithm.c -o dijkstras_algorithm
./dijkstras_algorithm
```

### Day 8 Examples (Dynamic Programming)
```bash
cd day-8

# Matrix Chain Multiplication
gcc -Wall -Wextra matrix_chain_multiplication.c -o matrix_chain_multiplication
./matrix_chain_multiplication < input/mcm_input.txt

# Longest Common Subsequence
gcc -Wall -Wextra longest_common_subsequence.c -o longest_common_subsequence
./longest_common_subsequence < input/lcs_input.txt
```

---

## License

This repository is maintained for educational purposes and academic coursework.
