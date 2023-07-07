#include <iostream>
#include <vector>
using namespace std;

int N, K, even_numbers, l, r, length, max_length;
vector<int> modified_sequences;

int main(int argc, char* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int temp;

    cin >> N >> K;
    
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp % 2 == 0) even_numbers++;
        else {
            modified_sequences.push_back(even_numbers);
            even_numbers = 0;
        }
    }
    if (even_numbers != 0) modified_sequences.push_back(even_numbers);

    r = K;
    for (int i = 0; i <= K && i < modified_sequences.size(); i++) length += modified_sequences[i];

    max_length = length;
    while (r < modified_sequences.size() - 1) {
        r++;
        length += modified_sequences[r];
        length -= modified_sequences[l];
        l++;
        
        if (length > max_length) max_length = length;
    }

    cout << max_length;
    
    return 0;
}