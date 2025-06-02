🧩 Sudoku Solver in C (Backtracking Approach)

📌 Project Overview

This project is a console-based Sudoku Solver developed in C language using the backtracking algorithm. It allows users to input a 9x9 Sudoku puzzle and solves it by recursively filling in the empty cells while adhering to Sudoku rules.

🧠 Algorithm Used: Backtracking

The backtracking algorithm systematically fills the board by:

1. Trying digits 1 to 9 in each empty cell.

2. Validating each move according to:

    -> Row constraints

    -> Column constraints

    -> 3x3 subgrid constraints

Backtracking when an invalid state is encountered, ensuring a correct and complete solution is found.

🧾 Input Format

1. The user inputs the Sudoku puzzle row by row

2. Each row contains 9 integers separated by spaces

3. The number 0 represents an empty cell to be filled by the solver


Example Input (one row per line):

5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
... (remaining 6 rows)

🖥 Program Features

1. Input validation and clean interface

2. Fast and efficient backtracking solver

3. Display of solved puzzle after computation

4. Handles puzzles with unique or multiple solutions


🛠 Technologies Used

1. Language: C

2. Algorithm: Backtracking

3. Concepts: Recursion, 2D arrays, constraint checking

🎯 Learning Outcomes

1. Understand and implement backtracking algorithms

2. Practice recursive programming in C

3. Learn how to handle user input and grid-based validation
