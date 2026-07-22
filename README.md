# DAAL — Design and Analysis of Algorithms Lab

Lab programs for the **Design and Analysis of Algorithms** course, written in C.

> **Compiler:** GCC (or any standard C compiler) &nbsp;|&nbsp; **Language:** C

---

## DAY 1 — Arrays

| # | File | Problem | Concepts |
|---|------|---------|----------|
| 1 | `first.c` | Find the **second smallest** and **second largest** elements | Single-pass min/max tracking |
| 2 | `second.c` | Compute the **prefix sum** array | Running sum |
| 3 | `third.c` | Count **duplicates** & find the **most repeating** element | Frequency counting, nested loops |
| 4 | `fourth.c` | **Right-rotate** an array by `k` positions | In-place swap (`EXCHANGE`) |

**Input:** reads from `text files/` directory &nbsp;•&nbsp; **Run:**

```bash
cd "DAY 1"
gcc first.c -o first && ./first
```

---

## DAY 2 — Recursion & File Handling

| # | File | Problem | Concepts |
|---|------|---------|----------|
| 1 | `first.c` | Convert first `n` decimal numbers to **binary** (recursive) | Recursion, CLI args, file I/O |
| 2 | `second.c` | Find **GCD** of number pairs (Euclidean algorithm, recursive) | Recursion, CLI args, file I/O |

**Input/Output:** `dat files/` directory &nbsp;•&nbsp; **Run:**

```bash
cd "DAY 2"

# Decimal → Binary
gcc first.c -o first
./first 150 "dat files/inDec.dat" "dat files/outBin.dat"

# GCD
gcc second.c -o second
./second "dat files/inGcd.dat" "dat files/outGcd.dat"
```

---

## 📁 Structure

```
DAAL/
├── DAY 1/
│   ├── first.c … fourth.c    # Source files
│   ├── text files/            # Input data
│   └── *.exe                  # Compiled binaries
├── DAY 2/
│   ├── first.c, second.c     # Source files
│   ├── first.txt, second.txt # Problem statements
│   ├── dat files/             # Input & output data
│   └── *.exe                  # Compiled binaries
└── README.md
```

---

*University coursework — for educational purposes.*
