// 엘리스와 밥이 경기를 함
// binary string이 주어짐 00011000처럼
// 0: false, 1: true
// 처음부터 돌아가면서 엘리스는 결과를 true로,
// 밥은 결과를 false로 만들기 위해 최적의 전략을 짬
// 010이 주어졌다면 턴은 2개 존재하고, 엘리스 먼저 시작
// 0 or 1 처럼 엘리스가 턴을 구성할 수 있음
// 그럼 밥은 1 and 0 처럼 턴을 구성할 수 있음

#include <bits/stdc++.h>
using namespace std;

#define ALICE   false
#define BOB     true
#define TRUE    '1'
#define FALSE   '0'

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string line;
        cin >> n >> line;

        bool win = false;
        if (line[0] == TRUE || line[n-1] == TRUE)
            win = true;
        else
            for (int i = 1; i < n; i++)
                if (line[i] == TRUE && line[i-1] == TRUE)
                    win = true;
        
        if (win)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}