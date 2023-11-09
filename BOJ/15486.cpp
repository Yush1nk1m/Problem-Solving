#include <iostream>
#include <vector>
using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct element {
    int time;
    int price;
} element;

int main(int argc, char* argv[]) {

    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int N;
    cin >> N;

    vector<element> table(N + 2);       // use index from 1 to N
    vector<int> result(N + 2);

    table[N + 1] = {0, 0};
    result[N + 1] = 0;

    for (int i = 1; i <= N; i++) {
        int T, P;
        cin >> T >> P;

        table[i].time = T;
        table[i].price = P;
    }

    if (table[N].time > 1) {    // base case: cannot consider the final day's counseling
        result[N] = 0;
    }
    else {                      // base case: can consider the final day's counseling
        result[N] = table[N].price;
    }

    for (int curr_day = N - 1; curr_day >= 1; curr_day--) {
        
        if (curr_day + table[curr_day].time > N + 1) {      // the case when the end time of the counseling exceeds day-N: cannot consider the current day's counseling
            result[curr_day] = result[curr_day + 1];
        }
        else {  // the case when the end time of the counseling does not exceed day-N: compare two cases, next day's optimal solution vs. the case when the current day's counseling is included
            result[curr_day] = MAX(
                table[curr_day].price + result[table[curr_day].time + curr_day],
                result[curr_day + 1]
            );
        }

    }

    cout << result[1];

    return 0;
}