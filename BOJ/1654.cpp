#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long K, N, result, max_length, min_length;
vector<long long> wires;

void findMaxFit(long long low, long long high) {
    int wire_number;
    long long len;
    while (low <= high) {
        len = (low + high) / 2;
        wire_number = 0;
        for (int i = 0; i < K; i++)
            wire_number += wires[i] / len;
        if (wire_number >= N) {
            if (result < len) result = len;
            low = len + 1;
        }
        else high = len - 1;
    }
}

int main(int argc, char* argv[]) {
    cin >> K >> N;

    wires.resize(K);
    for (int i = 0; i < K; i++) {
        cin >> wires[i];
        if (max_length < wires[i]) max_length = wires[i];
    }

    findMaxFit(1, max_length);


    cout << result;

    return 0;
}