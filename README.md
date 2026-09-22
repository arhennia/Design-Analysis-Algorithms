# Design & Analysis of Algorithms (DAAL)

A structured collection of C implementations exploring fundamental algorithms, data structures, and problem-solving techniques.

This repository documents hands-on lab implementations covering array manipulation, recursion, divide and conquer, heaps, and greedy algorithms.

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
- **Greedy Techniques** (Day 5)
- Dynamic Programming *(coming soon)*
- Graph Algorithms *(coming soon)*
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
└── day-5/
    ├── fractional_knapsack.c
    ├── fractional_knapsack.txt
    ├── huffman_coding.c
    └── huffman_coding.txt
```

---

## Compilation & Execution

Compile using GCC:

### Day 4 Example (Heaps)
```bash
cd day-4
gcc -Wall -Wextra person_heap.c -o person_heap
./person_heap
```

### Day 5 Examples (Greedy)
```bash
cd day-5

# Fractional Knapsack
gcc -Wall -Wextra fractional_knapsack.c -o fractional_knapsack
./fractional_knapsack

# Huffman Coding
gcc -Wall -Wextra huffman_coding.c -o huffman_coding
./huffman_coding
```

---

## License

This repository is maintained for educational purposes and academic coursework.
