#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> paper(100, vector<int>(100, 0));

    int paperNumber;
    cin >> paperNumber;

    for (int _ = 0; _ < paperNumber; _++)
    {
        int x, y;
        cin >> x; cin >> y;
        for (int r = x; r < x + 10; r++)
        {
            for (int c = y; c < y + 10; c++)
            {
                paper[r][c] = 1;
            }
        }
    }

    int area = 0;
    for (int r = 0; r < 100; r++)
    {
        for (int c = 0; c < 100; c++)
        {
            if (paper[r][c] == 1) area++;
        }
    }

    cout << area;

    return 0;
}