#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    vector<int> array = { 1, 1, 2, 2, 5, 6, 6, 7, 3, 3, 3, 4, 5, 5 };

    // 먼저 정렬한다.
    sort(array.begin(), array.end());

    // 정렬된 후 앞에서부터 탐색하며 중복되는 요소를 제거한다.
    // 반환된 이터레이터 뒤에 있는 요소는 제거한다.
    array.erase(unique(array.begin(), array.end()), array.end());
    
    for (int number : array)
        cout << number << ' ';
    cout << '\n';

    return 0;
}