#include <iostream>
#include <vector>
using namespace std;

vector<long long> heap;
int element_number;

inline void insert_heap(long long data) {
    element_number++;
    int index = element_number;
    
    if (heap.size() <= element_number) {
        heap.resize(heap.size() + 1000);
    }

    heap[index] = data;
    
    while (index / 2 >= 1 && heap[index / 2] > heap[index]) {
        long long temp = heap[index / 2];
        heap[index / 2] = heap[index];
        heap[index] = temp;

        index /= 2;
    }
}

inline long long delete_heap() {
    if (element_number == 0) {
        return 0;
    }
    int result = heap[1];

    heap[1] = heap[element_number];

    int index = 1;
    while (index * 2 + 1 <= element_number && (heap[index] > heap[index * 2] || heap[index] > heap[index * 2 + 1])) {
        if (heap[index * 2] < heap[index * 2 + 1]) {
            long long temp = heap[index * 2];
            heap[index * 2] = heap[index];
            heap[index] = temp;

            index = index * 2;
        }
        else {
            long long temp = heap[index * 2 + 1];
            heap[index * 2 + 1] = heap[index];
            heap[index] = temp;

            index = index * 2 + 1;
        }
    }

    element_number--;

    return result;
}

int N, x;

int main(int argc, char* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int _ = 0; _ < N; _++) {
        cin >> x;
        if (x == 0)
            cout << delete_heap() << '\n';
        else
            insert_heap(x);
    }

    return 0;
}