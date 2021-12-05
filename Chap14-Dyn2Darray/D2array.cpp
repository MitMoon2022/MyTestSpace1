// Dynamic two-dimensional arrays
#include <iostream>
#include <iomanip>

using namespace std;

void fill(int **p, int rowSize, int columnSize);    //take note of the ptr2ptr
void print(int **p, int rowSize, int columnSize);

int main()
{
    int **board;     //Data Type int, the variable(board) to be a pointer to pointer
                    //board and *board are pointers.
                    //board store the address of a ptr or array of ptr
                    //*board store the address of an int memory space or an array of int values.
    int rows;       // Line 2
    int columns;    // Line 3

    cout << "Line 4: Enter the number of rows "
         << "and columns: ";                    // Line 4
    cin >> rows >> columns;                     // Line 5
    cout << endl;                               // Line 6

    // Create the rows of board
    board = new int *[rows];    //create  an array of pointers of type int.
                                //assign the address of the array to board.
    // Create the columns of board
    for (int row = 0; row < rows; row++)  //For loop
        board[row] = new int[columns];   //create the colums
    
    // Insert elements into board
    fill(board, rows, columns);        //ptr2ptr board is passed.
    cout << "Ptr-2-Ptr: Board:" << endl; // Line 11
    
    // Output the elements of board
    print(board, rows, columns); // Line 12
    return 0;
}

//The function which fill in the matrix
void fill(int **p, int rowSize, int columnSize)
{
    for (int row = 0; row < rowSize; row++)
    {
        cout << "Enter " << columnSize << " number(s) for row "
             << "number " << row << ": ";
        for (int col = 0; col < columnSize; col++)
            cin >> p[row][col];     //able to use the [] array notation.
        cout << endl;
    }
}
void print(int **p, int rowSize, int columnSize)
{
    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < columnSize; col++)
            cout << setw(5) << p[row][col];
        cout << endl;
    }
}