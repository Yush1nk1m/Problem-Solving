#include <iostream>
#include <vector>
using namespace std;

static vector<int> array;
static vector<int> temp;

long long MergeSort(int left, int right);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    array.resize(N);
    temp.resize(N);

    for (int i = 0; i < N; i++)
        cin >> array[i];

    cout << MergeSort(0, N - 1);

    return 0;
}

long long MergeSort(int left, int right) {
    if (right - left < 1) return 0;

    int mid = left + (right - left) / 2;

    long long left_result = MergeSort(left, mid);
    long long right_result = MergeSort(mid + 1, right);

    for (int i = left; i <= right; i++)
        temp[i] = array[i];
    
    int left_pointer = left, right_pointer = mid + 1, i = left;
    long long result = 0;

    while (left_pointer <= mid && right_pointer <= right) {
        if (temp[left_pointer] <= temp[right_pointer]) {
            array[i++] = temp[left_pointer++];
        } else {
            array[i++] = temp[right_pointer++];
            result += (right_pointer - i);
        }
    }

    while (left_pointer <= mid) {
        array[i++] = temp[left_pointer++];
    }

    while (right_pointer <= right) {
        array[i++] = temp[right_pointer++];
    }

    return left_result + right_result + result;
}