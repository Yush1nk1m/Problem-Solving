#include <iostream>
using namespace std;

int x[1001], y[1001];
int x1, x2, y1, y2;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int temp_x, temp_y;

    cin >> x1 >> y1;
    x[x1]++; y[y1]++;

    cin >> temp_x >> temp_y;
    if (x1 != temp_x) x2 = temp_x;
    if (y1 != temp_y) y2 = temp_y;
    x[temp_x]++; y[temp_y]++;
    
    cin >> temp_x >> temp_y;
    if (x1 != temp_x) x2 = temp_x;
    if (y1 != temp_y) y2 = temp_y;
    x[temp_x]++; y[temp_y]++;
    
    if (x[x1] % 2 != 0) cout << x1 << ' ';
    else cout << x2 << ' ';

    if (y[y1] % 2 != 0) cout << y1;
    else cout << y2;
    
    return 0;
}