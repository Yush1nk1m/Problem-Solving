#include <iostream>
using namespace std;

int w[21][21][21];

int main(int argc, char* argv[])
{
    for (int a = 0; a <= 20; ++a)
    {
        for (int b = 0; b <= 20; ++b)
        {
            for (int c = 0; c <= 20; ++c)
            {
                if (a == 0 || b == 0 || c == 0) w[a][b][c] = 1;
                else if ((a < b) && (b < c)) w[a][b][c] = w[a][b][c-1] + w[a][b-1][c-1] - w[a][b-1][c];
                else w[a][b][c] = w[a-1][b][c] + w[a-1][b-1][c] + w[a-1][b][c-1] - w[a-1][b-1][c-1];
            }
        }
    }

    int a, b, c;
    while (1)
    {
        int result;
        cin >> a;
        cin >> b;
        cin >> c;

        if (a == -1 && b == -1 && c == -1)
            return 0;
        else if (a <= 0 || b <= 0 || c <= 0)
            result = w[0][0][0];
        else if (a > 20 || b > 20 || c > 20)
            result = w[20][20][20];
        else
            result = w[a][b][c];

        cout << "w(" << a << ", " << b << ", " << c << ") = " << result << '\n';
    }
}