#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S, P, left, right;
    cin >> S >> P;

    string DNA_string;
    cin >> DNA_string;

    unordered_map<char, int> DNA;
    DNA['A'] = 0;
    DNA['C'] = 0;
    DNA['G'] = 0;
    DNA['T'] = 0;

    int A, C, G, T;
    cin >> A >> C >> G >> T;

    for (int i = 0; i < P; i++)
        DNA[DNA_string[i]]++;
    
    int result = 0;
    left = 0;
    right = P - 1;
    while (right < S) {
        if (DNA['A'] >= A &&
            DNA['C'] >= C &&
            DNA['G'] >= G &&
            DNA['T'] >= T) result++;
        
        DNA[DNA_string[left++]]--;
        DNA[DNA_string[++right]]++;
    }

    cout << result;

    return 0;
}