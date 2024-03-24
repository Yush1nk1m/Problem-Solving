#include <iostream>
#include <vector>
#include <stack>
using namespace std;

static unsigned long long int factorial[21];
static inline int NthNotVisited(vector<bool>& visited, int N);
static inline int NotVisitedOrder(vector<bool>& visited, int number);
static inline void SubProblem1(int N);
static inline void SubProblem2(int N);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    factorial[0] = factorial[1] = 1;
    for (int i = 2; i <= 20; i++)
        factorial[i] = factorial[i-1] * i;

    int N, subProblem;
    cin >> N >> subProblem;
    
    if (subProblem == 1) {
        SubProblem1(N);
    }
    else if (subProblem == 2) {
        SubProblem2(N);
    }

    return 0;
}

static inline int NthNotVisited(vector<bool>& visited, int N) {
    int i = 0;
    while (N > 0) {
        i++;
        if (!visited[i])
            N--;
    }
    return i;
}

static inline int NotVisitedOrder(vector<bool>& visited, int number) {
    int order = 0;
    for (int i = 1; i <= number; i++)
        if (!visited[i])
            order++;
    return order;
}

static inline void SubProblem1(int N) {
    vector<bool> visited(N + 1, false);
    unsigned long long int order;
    cin >> order;
    order--;

    while (N > 0) {
        int quotient = order / factorial[N-1];
        int next = NthNotVisited(visited, quotient + 1);
        visited[next] = true;
        order -= (factorial[N-1] * quotient);
        N--;
        cout << next << ' ';
    }
}

static inline void SubProblem2(int N) {
    vector<int> sequence(N);
    vector<bool> visited(N + 1, false);
    for (int i = 0; i < N; i++)
        cin >> sequence[i];
    
    unsigned long long int result = 1;
    for (int digit : sequence) {
        int order = NotVisitedOrder(visited, digit);
        visited[digit] = true;
        result += (order - 1) * factorial[N - 1];
        N--;
    }

    cout << result;
}