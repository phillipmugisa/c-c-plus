# include <iostream>
# include <stdbool.h>

using namespace std;

// creating broad
int board[9][9] = { 
    {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
    {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
    {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
    {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
    {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
    {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
    {0, 0, 5, 2, 0, 6, 3, 0, 0}
};


bool isValidPlacement (int row, int col, int num);

bool hasEmptySpaces();

bool solveBoard ();

void printBoard();

int main(int argc, char * argv[])
{
    if(solveBoard())
        printBoard();
    else
        cout << "No solution!" << endl;

    
    return 0;
}

void printBoard()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "___ ___ ___ ___ ___ ___ ___ ___ ___ ";
        cout << endl;
    }
}

bool hasEmptySpaces(int & row, int & col)
{
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (board[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool solveBoard ()
{
    int row, col;

    // check if the board is filled
    if (!hasEmptySpaces(row, col))
        return true;


    for (int num = 1; num <= 9; num++)
    {
        if (isValidPlacement(row, col, num))
        {
            board[row][col] = num;
            // check if board can be completed if placement is made
            if (solveBoard())
                return true;
            // if not backtrack and set value back to 0 and try another value
            board[row][col] = 0;
        }
    }

    return false;
}

bool isValidPlacement (int row, int col, int num)
{

    // check the parent small grid
    int gridStartRow = row - row % 3;
    int gridStartCol = col - col % 3;

    for (int i = gridStartRow; i < gridStartRow + 3; i++)
    {
        for (int j = gridStartCol; j < gridStartCol + 3; j++)
        {
            if (board[i][j] == num)
                return false;
        }
    }

    // check rows
    for (int i = 0; i < 9; i++)
    {
        if (num == board[row][i])
        {
            return false;
        }
    }
    // check cols
    for (int i = 0; i < 9; i++)
    {
        if (num == board[i][col])
        {
            return false;
        }
    }   

    return true && board[row][col] == 0;
}