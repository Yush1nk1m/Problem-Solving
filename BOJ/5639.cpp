#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static vector<int> input;

static void PostorderTraversal(int begin, int end);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while (cin >> n)
        input.push_back(n);

    PostorderTraversal(0, input.size() - 1);

    return 0;
}

static void PostorderTraversal(int begin, int end) {
    if (begin == end) {
        cout << input[begin] << '\n';
        return;
    }

    int root = input[begin];

    int left = begin;
    while (left + 1 <= end && input[left + 1] < root)
        left++;
    
    // 왼쪽 서브 트리가 존재하는 경우
    if (left != begin)
        PostorderTraversal(begin + 1, left);
    
    int right = left;
    while (right + 1 <= end && input[right + 1] > root)
        right++;
    
    // 오른쪽 서브 트리가 존재하는 경우
    if (right != left)
        PostorderTraversal(left + 1, right);

    cout << input[begin] << '\n';
}
