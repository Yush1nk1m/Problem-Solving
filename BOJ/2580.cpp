#include <iostream>
#include <vector>
using namespace std;

int table[9][9];
vector<pair<int, int>> empties;

void dfs(int depth);

int main(int argc, char* argv[])
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for (int r = 0; r < 9; ++r)
    {
        for (int c = 0; c < 9; ++c)
        {
            cin >> table[r][c];
            if (table[r][c] == 0)
            {
                empties.push_back(pair<int, int>(r, c));
            }
        }
    }

    dfs(0);

    return 0;
}

void dfs(int depth)
{
    if (depth == empties.size())
    {
        for (int r = 0; r < 9; ++r)
        {
            for (int c = 0; c < 9; ++c)
            {
                cout << table[r][c] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }
    else
    {
        int row = empties[depth].first, col = empties[depth].second;
        for (int fill = 1; fill <= 9; ++fill)
        {
            bool isAvail = true;    // indicate if the value of a variable fill can be inserted into the empty cell
            
            for (int r = 0; (isAvail) && (r < 9); ++r)  // same column
                if (table[r][col] == fill)
                {
                    isAvail = false;
                    break;
                }
            
            for (int c = 0; (isAvail) && (c < 9); ++c)
                if (table[row][c] == fill)
                {
                    isAvail = false;
                    break;
                }
            
            for (int r = row - (row % 3); (isAvail) && (r < row - (row % 3) + 3); ++r)
                for (int c = col - (col % 3); (isAvail) && (c < col - (col % 3) + 3); ++c)
                    if (table[r][c] == fill)
                    {
                        isAvail = false;
                        break;
                    }
            
            if (isAvail)
            {
                table[row][col] = fill;
                dfs(depth + 1);
                table[row][col] = 0;
            }
        }
    }
}