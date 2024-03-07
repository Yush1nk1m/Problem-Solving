#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> positives;
    vector<int> negatives;

    int N;
    cin >> N;
    for (int _ = 0; _ < N; _++) {
        int number;
        cin >> number;

        if (number <= 0) {
            negatives.push_back(number);
        } else {
            positives.push_back(number);
        }
    }

    sort(positives.begin(), positives.end());
    sort(negatives.rbegin(), negatives.rend());

    int answer = 0;
    int positives_index = 0, negatives_index = 0;
    if (positives.size() % 2 != 0) answer += positives[positives_index++];
    if (negatives.size() % 2 != 0) answer += negatives[negatives_index++];

    while (positives_index < positives.size()) {
        int first = positives[positives_index];
        int second = positives[positives_index + 1];

        int adder = (first + second < first * second) ? (first * second) : (first + second);
        positives_index += 2;
        answer += adder;
    }

    while (negatives_index < negatives.size()) {
        int first = negatives[negatives_index];
        int second = negatives[negatives_index + 1];

        int adder = (first + second < first * second) ? (first * second) : (first + second);
        negatives_index += 2;
        answer += adder;
    }

    cout << answer;

    return 0;
}