#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int** matrix;
    
    matrix = new int*[9];
    for (int i = 0; i < 9; i++) matrix[i] = new int[9];

    int max = numeric_limits<int>::min();
    int maxRow, maxCol;
    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            cin >> matrix[r][c];
            if (matrix[r][c] > max)
            {
                maxRow = r;
                maxCol = c;
                max = matrix[r][c];
            }
        }
    }

    cout << max << endl;
    cout << maxRow + 1 << " " << maxCol + 1;

    return 0;
}