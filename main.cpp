#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <utility>

using namespace std;

// Problem 1: Read matrices from a file
bool loadMatrices(const string& filename, int& n,
                  vector<vector<int>>& A,
                  vector<vector<int>>& B)
{
    ifstream inputFile(filename);

    if (!inputFile)
    {
        cerr << "Error: Could not open file." << endl;
        return false;
    }

    inputFile >> n;

    if (n <= 0)
    {
        cerr << "Error: Matrix size must be positive." << endl;
        return false;
    }

    A.resize(n, vector<int>(n));
    B.resize(n, vector<int>(n));

    // Read Matrix A
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!(inputFile >> A[i][j]))
            {
                cerr << "Error: Not enough values for Matrix A." << endl;
                return false;
            }
        }
    }

    // Read Matrix B
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!(inputFile >> B[i][j]))
            {
                cerr << "Error: Not enough values for Matrix B." << endl;
                return false;
            }
        }
    }

    return true;
}

// Print a matrix
void printMatrix(const vector<vector<int>>& matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

// Problem 2: Add two matrices
void addMatrices(const vector<vector<int>>& A,
                 const vector<vector<int>>& B)
{
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "A + B:" << endl;
    printMatrix(result);
}

// Problem 3: Multiply two matrices
void multiplyMatrices(const vector<vector<int>>& A,
                      const vector<vector<int>>& B)
{
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "A * B:" << endl;
    printMatrix(result);
}

// Problem 4: Diagonal sums
void diagonalSums(const vector<vector<int>>& matrix)
{
    int n = matrix.size();

    int mainSum = 0;
    int secondarySum = 0;

    for (int i = 0; i < n; i++)
    {
        mainSum += matrix[i][i];
        secondarySum += matrix[i][n - 1 - i];
    }

    cout << "Diagonal sums for Matrix A:" << endl;
    cout << "Main diagonal sum: " << mainSum << endl;
    cout << "Secondary diagonal sum: " << secondarySum << endl;
}

// Problem 5: Swap two rows
void swapRows(vector<vector<int>>& matrix, int row1, int row2)
{
    int n = matrix.size();

    if (row1 < 0 || row1 >= n || row2 < 0 || row2 >= n)
    {
        cout << "Invalid row index." << endl;
        return;
    }

    swap(matrix[row1], matrix[row2]);
}

// Problem 6: Swap two columns
void swapColumns(vector<vector<int>>& matrix, int col1, int col2)
{
    int n = matrix.size();

    if (col1 < 0 || col1 >= n || col2 < 0 || col2 >= n)
    {
        cout << "Invalid column index." << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        swap(matrix[i][col1], matrix[i][col2]);
    }
}

// Problem 7: Update one matrix element
void updateElement(vector<vector<int>>& matrix,
                   int row, int column, int newValue)
{
    int n = matrix.size();

    if (row < 0 || row >= n || column < 0 || column >= n)
    {
        cout << "Invalid matrix index." << endl;
        return;
    }

    matrix[row][column] = newValue;
}

int main()
{
    string filename;
    int n;

    vector<vector<int>> A;
    vector<vector<int>> B;

    cout << "Enter input filename: ";
    cin >> filename;

    if (!loadMatrices(filename, n, A, B))
    {
        return 1;
    }

    // Problem 1
    cout << "Matrix A:" << endl;
    printMatrix(A);

    cout << "Matrix B:" << endl;
    printMatrix(B);

    // Problem 2
    addMatrices(A, B);

    // Problem 3
    multiplyMatrices(A, B);

    // Problem 4
    diagonalSums(A);

    // Problem 5
    vector<vector<int>> rowMatrix = A;
    swapRows(rowMatrix, 0, 2);

    cout << "Problem 5 - Rows 0 and 2 swapped:" << endl;
    printMatrix(rowMatrix);

    // Problem 6
    vector<vector<int>> columnMatrix = A;
    swapColumns(columnMatrix, 0, 2);

    cout << "Problem 6 - Columns 0 and 2 swapped:" << endl;
    printMatrix(columnMatrix);

    // Problem 7
    vector<vector<int>> updatedMatrix = A;
    updateElement(updatedMatrix, 1, 2, 99);

    cout << "Problem 7 - Updated matrix:" << endl;
    printMatrix(updatedMatrix);

    return 0;
}