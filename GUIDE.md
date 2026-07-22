# 📘 GUIDE — How to Add New Lab Days & Organize Files

This is your cheat sheet. Follow these steps whenever you get a new lab day.

---

## Step 1: Create the folder

Use lowercase with a hyphen. No spaces!

```
✅  day-3
✅  day-4
❌  DAY 3
❌  Day 3
❌  day 3
```

Create it from your terminal:

```bash
# Windows (PowerShell)
mkdir day-3

# Linux / Mac
mkdir day-3
```

---

## Step 2: Name your C files descriptively

Don't use generic names like `first.c`, `second.c`. Name them after what the
program actually does. Use lowercase with underscores.

```
✅  binary_search.c
✅  merge_sort.c
✅  linked_list_insert.c
❌  first.c
❌  second.c
❌  BinarySearch.c
❌  binary search.c       (no spaces!)
```

---

## Step 3: Organize input/output files

Put all input & output data files inside a subfolder called `input/` or `data/`.

```
day-3/
├── binary_search.c
├── merge_sort.c
└── input/
    ├── search_data.txt
    └── sort_data.txt
```

Create it:

```bash
mkdir day-3/input
```

If you have problem statement `.txt` files, keep them next to the `.c` file
with the same name:

```
day-3/
├── binary_search.c
├── binary_search.txt      ← problem statement
├── merge_sort.c
├── merge_sort.txt          ← problem statement
└── input/
```

---

## Step 4: Compile your code

### Basic (no file arguments)

If your program reads from a hardcoded file path (like day-1 programs):

```bash
cd day-3
gcc binary_search.c -o binary_search
./binary_search
```

On **Windows (PowerShell)**, use `.\` instead of `./`:

```powershell
cd day-3
gcc binary_search.c -o binary_search
.\binary_search
```

### With command-line arguments

If your program uses `argc` / `argv` (like day-2 programs):

```bash
cd day-3
gcc merge_sort.c -o merge_sort
./merge_sort input/unsorted.txt input/sorted_output.txt
```

PowerShell:

```powershell
.\merge_sort input\unsorted.txt input\sorted_output.txt
```

### With math library (-lm)

If you use `#include <math.h>`, add `-lm` at the end:

```bash
gcc my_program.c -o my_program -lm
```

---

## Step 5: Handle the .exe files

After compiling, gcc creates an executable (`.exe` on Windows, no extension on
Linux). **Don't commit these to git** — they can be regenerated anytime.

These are already ignored if you have a `.gitignore`. If not, create one:

```bash
# In the DAAL/ root folder, create .gitignore with:
echo "*.exe" >> .gitignore
echo "*.out" >> .gitignore
```

To clean up existing `.exe` files in a folder:

```powershell
# PowerShell — delete all .exe in day-3
Remove-Item day-3\*.exe
```

```bash
# Linux / Mac
rm day-3/*.exe
```

---

## Step 6: Update the README

Copy-paste this template into `README.md` for each new day. Replace the
placeholders with your actual info:

```markdown
---

## day-N — Topic Name

| # | File | Problem | Concepts |
|---|------|---------|----------|
| 1 | `file_name.c` | Brief problem description | Key concepts |
| 2 | `another_file.c` | Brief problem description | Key concepts |

**Input:** reads from `input/` directory &nbsp;•&nbsp; **Run:**

\```bash
cd day-N
gcc file_name.c -o file_name && ./file_name
\```
```

And add the folder to the **Structure** section at the bottom:

```markdown
├── day-N/
│   ├── file_name.c
│   ├── another_file.c
│   └── input/
```

---

## Quick Reference — Common Errors & Fixes

| Error | Cause | Fix |
|-------|-------|-----|
| `gcc: No such file or directory` | Wrong filename or not in the right folder | `cd` into the correct `day-N/` folder first |
| `cannot open input file` | Hardcoded path is wrong | Check the path inside `fopen()` matches your folder name (e.g., `"input/data.txt"` not `"text files/data.txt"`) |
| `undefined reference to sqrt/pow` | Missing math library | Add `-lm` flag: `gcc file.c -o file -lm` |
| `Permission denied` (Linux) | Executable not marked | Run `chmod +x ./program_name` |
| File runs but no output | Output went to a file | Check if your program writes to a file via `fprintf` — look in `input/` or `data/` |

---

## Full Example — Adding Day 3

```bash
# 1. Create folder + input subfolder
mkdir day-3
mkdir day-3/input

# 2. Write your C files in day-3/ (use VS Code, vim, etc.)
#    Name them: bubble_sort.c, linear_search.c, etc.

# 3. Add input data
#    Save test data to day-3/input/numbers.txt

# 4. Compile & run
cd day-3
gcc bubble_sort.c -o bubble_sort
./bubble_sort

# 5. Clean up .exe before committing
del *.exe          # PowerShell
# rm *.o *.out     # Linux/Mac

# 6. Update README.md with the new day's table
```

---

## Naming Convention Summary

| What | Convention | Example |
|------|-----------|---------|
| Folders | `day-N` | `day-1`, `day-2`, `day-3` |
| C source files | `snake_case.c` | `merge_sort.c`, `gcd_recursive.c` |
| Problem statements | same name `.txt` | `merge_sort.txt` |
| Input data folder | `input/` or `data/` | `day-3/input/` |
| Input/output files | descriptive | `numbers.txt`, `inGcd.dat` |
| Executables | same as source (no ext) | `merge_sort` (auto-generated) |
