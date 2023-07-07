#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, result, temp;
vector<int> cards;

int main(int argc, char* argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    cards.resize(N);

    for (int i = 0; i < N; i++)
        cin >> cards[i];
    
    sort(cards.begin(), cards.end());

    for (int first = 0; first <= N - 3; first++) {
        for (int second = first + 1; second <= N - 2; second++) {
            for (int third = second + 1; third <= N - 1 ; third++) {
                temp = cards[first] + cards[second] + cards[third];
                if (temp <= M && temp > result) result = temp;
                else if (temp > M) break;
                    
            }
        }
    }

    cout << result;

    return 0;
}