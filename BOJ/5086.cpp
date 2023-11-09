#include <iostream>
using namespace std;

int main()
{
    while (true)
    {
        int left, right;
        cin >> left; cin >> right;

        if (left == 0 && right == 0)
        {
            break;
        }

        if (left == 0 || right == 0)
        {
            cout << "neither\n";
        }
        else if (right % left == 0)
        {
            cout << "factor\n";
        }
        else if (left % right == 0)
        {
            cout << "multiple\n";
        }
        else
        {
            cout << "neither\n";
        }
    }
    
    return 0;
}