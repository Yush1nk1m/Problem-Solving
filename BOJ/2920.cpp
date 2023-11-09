#include <iostream>
using namespace std;

int array[8];

int main(int argc, char* argv[])
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < 8; ++i)
    {
        cin >> array[i];
    }

    bool isAscending = true, isDescending = true;

    for (int i = 1; i < 8; ++i)
    {
        if (array[i-1] < array[i]) isDescending = false;
        if (array[i-1] > array[i]) isAscending = false;
    }

    if (!isAscending && !isDescending) cout << "mixed";
    else if (isAscending) cout << "ascending";
    else cout << "descending";

    return 0;
}