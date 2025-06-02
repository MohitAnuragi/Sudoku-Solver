/* ****** SUDOKU SOLVER ******
PROBLEM OVERVIEW :-
-> grid layout : sudoku consists of a 9x9 grid, divided into 9 squares of 3x3 cells each.
-> Starting Number : The puzzle starts with some cells already filles with numbers from 1 to 9.
-> Objective : fill all empty cells with number from 1 to 9.
-> Row rule : each row must contain unique numbers from 1 to 9, without repitation.
-> Column rule :  each column also must contain unique numbers from 1 to 9, without repitation.
-> Square rule : each of nine 3x3 square must contain unique numbers from 1 to 9.

*/
/*  Aproch :-
follow backtracking.
0 for empty block.
*/
#include <stdio.h>

// static input for testing
// int puzzle[9][9] = { // 0 for empty slot(box)
//     {3, 0, 0, 0, 2, 0, 0, 7, 0},
//     {9, 0, 0, 5, 0, 0, 0, 1, 4},
//     {0, 1, 6, 3, 7, 0, 0, 0, 8},
//     {2, 0, 0, 8, 0, 0, 0, 0, 1},
//     {5, 0, 0, 0, 4, 1, 8, 0, 0},
//     {0, 8, 9, 0, 0, 0, 0, 5, 0},
//     {0, 0, 5, 0, 1, 0, 2, 8, 0},
//     {0, 4, 0, 0, 0, 6, 0, 9, 3},
//     {7, 3, 1, 0, 8, 2, 0, 0, 0}};

// user input
void inputSudoku(int puzzle[9][9])
{
    printf("\nEnter the Sudoku puzzle row by row (use 0 for empty cells):\n");
    for (int i = 0; i < 9; ++i)
    {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < 9; ++j)
        {
            scanf("%d", &puzzle[i][j]);
            // Input validation (optional)
            if (puzzle[i][j] < 0 || puzzle[i][j] > 9)
            {
                printf("\nInvalid input. Enter numbers between 0 and 9 only.\n");
                --j; // Re-do current column
            }
        }
    }
}

// printing the puzzle
void print_puzzle(int puzzle[9][9])
{
    printf("\n+-------+-------+-------+");
    for (int row = 0; row < 9; row++)
    {
        if (row % 3 == 0 && row != 0)
        {
            printf("\n|-------+-------+-------|");
        }
        printf("\n");
        for (int col = 0; col < 9; col++)
        {
            if (col % 3 == 0)
            {
                printf("| ");
            }
            if (puzzle[row][col] != 0)
            {
                printf("%d ", puzzle[row][col]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("|");
    }
    printf("\n+-------+-------+-------+\n");
}

// check the puzzle is valid or Not
int valid_move(int puzzle[9][9], int row, int col, int val)
{
    // row valid check
    for (int i = 0; i < 9; i++)
    {
        if (puzzle[row][i] == val)
            return 0;
    }
    // column valid check
    for (int i = 0; i < 9; i++)
    {
        if (puzzle[i][col] == val)
            return 0;
    }
    // 3x3 grid valid check
    // going to the starting of the row of puzzle
    int r = row - row % 3;
    int c = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (puzzle[r + i][c + j] == val)
            {
                return 0;
            }
        }
    }
    return 1;
};

// Solve puzzle(main Method Imp)
int solve_puzzle(int puzzle[9][9], int row, int col)
{

    // if col reach end of the grid(9th Index)
    if (col == 9)
    {
        if (row == 8)
        {
            return 1; // successfully solve the puzzle
        }
        row++;
        col = 0;
    }

    // if puzzle filled
    if (puzzle[row][col] > 0)
    {
        return solve_puzzle(puzzle, row, col + 1);
    }
    // filling the puzzle
    for (int i = 1; i <= 9; i++)
    {
        if (valid_move(puzzle, row, col, i))
        {
            puzzle[row][col] = i;
            if (solve_puzzle(puzzle, row, col + 1)) // solve recursivilly of all the elements of selected row
                return 1;
            puzzle[row][col] = 0; // reset the elements(backtrack)
        }
    }
    return 0;
};
int main()
{
    printf("\nWelcome to SUDOKU Solver!!");
    int puzzle[9][9];
    inputSudoku(puzzle);
    printf("\nOriginal puzzle : ");
    print_puzzle(puzzle);
    if (solve_puzzle(puzzle, 0, 0))

    {
        printf("\n The puzzle is solved : ");
        print_puzzle(puzzle);
    }
    else
    {
        printf("\n The puzzle is not solvable!!.\n");
    }
}
