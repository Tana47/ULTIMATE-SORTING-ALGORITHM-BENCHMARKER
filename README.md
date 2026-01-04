# ⚡ ULTIMATE-SORTING-ALGORITHM-BENCHMARKER

A high-performance command-line tool written in C that benchmarks the efficiency of **14 different sorting algorithms**. 

It measures **Execution Time** (up to 8 decimal places) and **Peak Heap Memory Usage** to provide a deep comparison between in-place sorts (like Quick Sort) and memory-heavy sorts (like Merge Sort).

## 🚀 Features
* **Precision Timing:** benchmarks sort time in seconds with high precision.
* **Memory Tracking:** Custom memory allocator tracks peak heap usage in bytes.
* **Flexible Input:** Use auto-generated random datasets or input your own arrays.
* **Comparison Mode:** Run a single algorithm or compare all 14 at once on the exact same dataset.

## 🧠 Supported Algorithms
| Basic Sorts | Efficient Sorts | Linear/Special Sorts |
| :--- | :--- | :--- |
| Bubble Sort | Quick Sort | Counting Sort |
| Insertion Sort | Merge Sort (Recursive) | Radix Sort |
| Selection Sort | Merge Sort (Iterative) | Tim Sort |
| Cocktail Shaker Sort | Heap Sort | Cycle Sort |
| Comb Sort | Shell Sort | |

## 🛠️ Installation & Compilation

Since this project separates logic into multiple files for modularity, you must link them during compilation.

**Prerequisites:**
* GCC Compiler (or Clang)

**Compile Command:**
Run this in your terminal inside the project folder:

```bash
gcc main.c \
sorts/memory.c \
sorts/bubble_sort.c \
sorts/insertion_sort.c \
sorts/selection_sort.c \
sorts/quick_sort.c \
sorts/merge_sort.c \
sorts/merge_sort_iterative.c \
sorts/heap_sort.c \
sorts/shell_sort.c \
sorts/radix_sort.c \
sorts/tim_sort.c \
sorts/counting_sort.c \
sorts/cocktail_sort.c \
sorts/comb_sort.c \
sorts/cycle_sort.c \
-o benchmark
```
## 🙏 Note Of Thanks

Thanks for using one of my first publicly released projects! 

If you have any complaints, suggestions, or feedback, please feel 
free to contact me at my 

GitHub    https://github.com/Tana47
LinkedIn  www.linkedin.com/in/tanay-reddy-a76a80385
Instagram https://www.instagram.com/tanay_reddy_?igsh=MThleWdtYzIxdDVnYw%3D%3D&utm_source=qr

