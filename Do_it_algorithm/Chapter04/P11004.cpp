#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int>& array, int left, int right, int K);
int partition(vector<int>& array, int left, int right);
void swap(vector<int>& A, int i, int j);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> array(N);

    for (int i = 0; i < N; i++)
        cin >> array[i];
    
    QuickSort(array, 0, N - 1, K - 1);
    cout << array[K - 1];

    return 0;
}

void QuickSort(vector<int>& array, int left, int right, int K) {
    int pivot = partition(array, left, right);

    if (pivot == K) return;
    else if (K < pivot) QuickSort(array, left, pivot - 1, K);
    else QuickSort(array, pivot + 1, right, K);
}

int partition(vector<int>& array, int left, int right) {
    if (left + 1 == right) {
        if (array[left] > array[right])
            swap(array, left, right);
        return right;
    }

    int mid = (left + right) / 2;
    swap(array, left, mid);
    int pivot = array[left];
    int start = left + 1, end = right;

    while (start <= end) {
        while (array[start] < pivot && start < array.size() - 1) start++;
        while (array[end] > pivot && end > 0) end--;

        if (start <= end) swap(array, start++, end--);
    }

    array[left] = array[end];
    array[end] = pivot;
    return end;
}

void swap(vector<int>& array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}