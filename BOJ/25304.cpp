#include <iostream>
using namespace std;

int main()
{
    int receiptTotal, total = 0, kinds, price, number;
    cin >> receiptTotal;
    cin >> kinds;
    
    for (int i = 0; i < kinds; i++)
    {
        cin >> price;
        cin >> number;
        total += (price * number);
    }

    if (receiptTotal == total)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;   
}