# DAAL — Design and Analysis of Algorithms Lab

Lab programs for the **Design and Analysis of Algorithms** course, written in C. Each day's folder contains the source files, compiled executables, and any associated input/output data files.

---

## 📁 Repository Structure

```
DAAL/
├── DAY 1/
│   ├── first.c          # Second smallest & second largest element in an array
│   ├── second.c         # Prefix sum array
│   ├── third.c          # Duplicate count & most repeating element
│   ├── fourth.c         # Right-rotate an array by k positions
│   ├── text files/      # Input data files (.txt)
│   └── *.exe            # Compiled executables
│
├── DAY 2/
│   ├── first.c          # Decimal → Binary conversion using recursion (file I/O, CLI args)
│   ├── first.txt        # Problem statement for first.c
│   ├── second.c         # GCD of number pairs using recursion (file I/O, CLI args)
│   ├── second.txt       # Problem statement for second.c
│   ├── dat files/       # Input & output data files (.dat)
│   └── *.exe            # Compiled executables
│
└── README.md
```

---

## 📋 Program Index

### DAY 1 — Arrays

| # | File | Problem | Key Concepts |
|---|------|---------|--------------|
| 1 | `first.c` | Find the **second smallest** and **second largest** elements in an array | Single-pass min/max tracking, file I/O |
| 2 | `second.c` | Compute the **prefix sum** array | Running sum, file I/O |
| 3 | `third.c` | Count **duplicate values** and find the **most repeating** element | Frequency counting (brute-force), nested loops |
| 4 | `fourth.c` | **Right-rotate** an array by `k` positions | In-place swap via `EXCHANGE`, iterative rotation |

### DAY 2 — Recursion & File Handling

| # | File | Problem | Key Concepts |
|---|------|---------|--------------|
| 1 | `first.c` | Convert the first `n` decimal numbers from a file to **binary** using recursion | Recursion, command-line arguments (`argc`/`argv`), file I/O |
| 2 | `second.c` | Find the **GCD** of pairs of numbers using the Euclidean algorithm (recursive) | Recursion, command-line arguments, file I/O |

---

## 🚀 How to Compile & Run

All programs are written in standard **C** and can be compiled with `gcc`.

### DAY 1 programs (read input from `text files/`)

```bash
cd "DAY 1"
gcc first.c -o first
./first
```

### DAY 2 programs (use command-line arguments)

```bash
cd "DAY 2"

# Decimal to Binary — args: <n> <input_file> <output_file>
gcc first.c -o first
./first 150 "dat files/inDec.dat" "dat files/outBin.dat"

# GCD — args: <input_file> <output_file>
gcc second.c -o second
./second "dat files/inGcd.dat" "dat files/outGcd.dat"
```

---

## 🛠 Prerequisites

- **GCC** (or any standard C compiler)
- A terminal / command prompt

---

## 📄 License

University coursework — for educational purposes.
