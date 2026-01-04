========================================================================
                  ULTIMATE SORTING ALGORITHM BENCHMARKER
                                Version 1.3
========================================================================

1. OVERVIEW
------------------------------------------------------------------------
This project is a benchmarking tool written in C. 
It allows users to compare the efficiency of 14 different sorting 
algorithms. It measures:
  - Execution Time (up to 8 decimal places)
  - Peak Heap Memory Usage (in bytes)

It supports both random dataset generation and custom user input.

2. FOLDER STRUCTURE
------------------------------------------------------------------------
Project_Folder/
  ├── main.c                  # The main menu and benchmarking engine
  ├── README.txt              # This file
  └── sorts/                  # Folder containing all algorithms
       ├── sorts.h            # Header file (prototypes & memory macros)
       ├── memory.c           # Custom memory tracking logic
       ├── bubble_sort.c
       ├── insertion_sort.c
       ├── selection_sort.c
       ├── quick_sort.c
       ├── merge_sort.c
       ├── merge_sort_iterative.c
       ├── heap_sort.c
       ├── shell_sort.c
       ├── radix_sort.c
       ├── tim_sort.c
       ├── counting_sort.c
       ├── cocktail_sort.c
       ├── comb_sort.c
       └── cycle_sort.c

3. SUPPORTED ALGORITHMS
------------------------------------------------------------------------
1.  Bubble Sort          8.  Shell Sort
2.  Insertion Sort       9.  Radix Sort
3.  Selection Sort       10. Tim Sort
4.  Quick Sort           11. Counting Sort
5.  Merge Sort (Rec)     12. Cocktail Shaker Sort
6.  Merge Sort (Iter)    13. Comb Sort
7.  Heap Sort            14. Cycle Sort

4. COMPILATION INSTRUCTIONS
------------------------------------------------------------------------
Because this project uses multiple files, you cannot use the standard 
"Play" button in VS Code. You must link all files together using the 
terminal.

Open your terminal in the project folder and run this EXACT command:

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

(Note: If pasting as one line, remove the backslashes '\')

5. HOW TO RUN
------------------------------------------------------------------------
After compiling, run the program using:

   ./benchmark

6. HOW TO USE
------------------------------------------------------------------------
Step 1: Choose Data Source
   - Option 1: Input your own numbers (e.g., "5 10 2 99").
   - Option 2: Auto-generate 100 random numbers.

Step 2: Choose Algorithms
   - Enter the numbers of the algorithms you want to test.
   - Example: "1 4" runs Bubble Sort and Quick Sort.
   - Example: "*" runs ALL algorithms.

Step 3: Analyze Results
   - The first run will print the "Sorted Result" to verify correctness.
   - A table will follow showing the Time and Peak Memory for each.

7. UNDERSTANDING MEMORY USAGE
------------------------------------------------------------------------
You might notice some algorithms (like Bubble, Quick, Insertion) show
"0 bytes" of memory usage. This is normal!

- 0 bytes: The algorithm is "In-Place." It uses Stack memory (variables)
  rather than Heap memory (malloc). This is very efficient.
- >0 bytes: The algorithm (like Merge Sort) requires extra space to 
  create temporary arrays during the sorting process.

========================================================================
Thanks for using one of my first publicly released projects! 

If you have any complaints, suggestions, or feedback, please feel 
free to contact me at my 

GitHub    https://github.com/Tana47
LinkedIn  www.linkedin.com/in/tanay-reddy-a76a80385
Instagram https://www.instagram.com/tanay_reddy_?igsh=MThleWdtYzIxdDVnYw%3D%3D&utm_source=qr
========================================================================
