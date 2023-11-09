#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<priority_queue<long long, vector<long long>, greater<long long>>> pq_vector;
int N, M;
long long status;
long long max_status = -1, min_status = 1000000001;
int max_index, min_index;
long long result;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> M;

    pq_vector.resize(N);
    for (int i = 0; i < N; i++) {
        for (int _ = 0; _ < M; _++) {
            long long element;
            cin >> element;

            pq_vector[i].push(element);
        }
    }

    for (int i = 0; i < N; i++) {
        long long element = pq_vector[i].top();

        if (element < min_status) {
            min_status = element;
            min_index = i;
        }
        if (element > max_status) {
            max_status = element;
            max_index = i;
        }
    }
    result = max_status - min_status;

    while (1) {
        pq_vector[min_index].pop();
        min_status = 1000000001;
        if (pq_vector[min_index].empty()) break;

        for (int i = 0; i < N; i++) {
            long long element = pq_vector[i].top();

            if (element < min_status) {
                min_status = element;
                min_index = i;
            }
            if (element > max_status) {
                max_status = element;
                max_index = i;
            }
        }
        
        if (max_status - min_status < result) result = max_status - min_status;
    }

    cout << result;

    return 0;
}