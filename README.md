# DAAL — Design and Analysis of Algorithms Lab

Lab programs for the **Design and Analysis of Algorithms** course, written in C.

> **Compiler:** GCC (or any standard C compiler) &nbsp;|&nbsp; **Language:** C

---

## day-1 — Arrays

| # | File | Problem | Concepts |
|---|------|---------|----------|
| 1 | `second_smallest_largest.c` | Find the **second smallest** and **second largest** elements | Single-pass min/max tracking |
| 2 | `prefix_sum.c` | Compute the **prefix sum** array | Running sum |
| 3 | `duplicate_count.c` | Count **duplicates** & find the **most repeating** element | Frequency counting, nested loops |
| 4 | `rotate_array.c` | **Right-rotate** an array by `k` positions | In-place swap (`EXCHANGE`) |

**Input:** reads from `input/` directory &nbsp;•&nbsp; **Run:**

```bash
cd day-1
gcc prefix_sum.c -o prefix_sum && ./prefix_sum
```

---

## day-2 — Recursion & File Handling

| # | File | Problem | Concepts |
|---|------|---------|----------|
| 1 | `decimal_to_binary.c` | Convert first `n` decimal numbers to **binary** (recursive) | Recursion, CLI args, file I/O |
| 2 | `gcd_recursive.c` | Find **GCD** of number pairs (Euclidean algorithm, recursive) | Recursion, CLI args, file I/O |

**Input/Output:** `data/` directory &nbsp;•&nbsp; **Run:**

```bash
cd day-2

# Decimal → Binary
gcc decimal_to_binary.c -o decimal_to_binary
./decimal_to_binary 150 data/inDec.dat data/outBin.dat

# GCD
gcc gcd_recursive.c -o gcd_recursive
./gcd_recursive data/inGcd.dat data/outGcd.dat
```

---

## 📁 Structure

```
DAAL/
├── day-1/
│   ├── second_smallest_largest.c
│   ├── prefix_sum.c
│   ├── duplicate_count.c
│   ├── rotate_array.c
│   └── input/             # Input text files
├── day-2/
│   ├── decimal_to_binary.c
│   ├── decimal_to_binary.txt   # Problem statement
│   ├── gcd_recursive.c
│   ├── gcd_recursive.txt       # Problem statement
│   └── data/                   # Input & output .dat files
└── README.md
```

---

*University coursework — for educational purposes.*
