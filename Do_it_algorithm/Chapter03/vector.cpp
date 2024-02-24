#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    // declaration
    vector<int> A;

    // insertion
    A.push_back(1);
    A.insert(A.begin(), 7);
    A.insert(A.begin() + 2, 10);

    // value change
    A[4] = -5;

    // deletion
    A.pop_back();
    A.erase(A.begin() + 3);
    A.clear();

    // information extraction
    A.size();
    A.front();
    A.back();
    A[3];
    A.at(5);
    A.begin();
    A.end();
}