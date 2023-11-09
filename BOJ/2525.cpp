#include <iostream>
using namespace std;

int main()
{
    int hours, minutes, bake;
    cin >> hours;
    cin >> minutes;
    cin >> bake;

    minutes += bake;
    hours += (minutes / 60);
    
    minutes %= 60;
    hours %= 24;

    cout << hours << " " << minutes;
    return 0;
}