#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char character;
    map<char, Node*> childs;
    Node(char character): character(character) {} 
};

int N;
Node* root;

inline void printTree() {
    Node* curr = root;
    queue<Node*> q;
    for (pair<char, Node*> p : curr->childs)
        q.push(p.second);
    while (!q.empty()) {
        int qSize = q.size();
        while (qSize--) {
            curr = q.front();
            q.pop();
            cout << "[" << curr->character << "]" << ' ';

            for (pair<char, Node*> p : curr->childs)
                q.push(p.second);            
        }
        cout << endl;
    }
    cout << endl;
}
inline void initializeTree(vector<string>& words);
void freeMemory(Node* curr);
inline int calcTypeCount(vector<string>& words);
inline double solve();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> N) {
        cout << fixed << setprecision(2) << solve() << '\n';
    }

    return 0;
}

inline void initializeTree(vector<string>& words) {
    root = new Node('\0');
    for (string word : words) {
        Node* curr = root;
        for (char c : word) {
            if (curr->childs.find(c) == curr->childs.end())
                curr->childs[c] = new Node(c);
            curr = curr->childs[c];
        }
    }
}

void freeMemory(Node* curr) {
    if (!((curr->childs).empty()))
        for (pair<char, Node*> p : curr->childs)
            freeMemory(p.second);
    delete curr;
    curr = NULL;
}

inline int calcTypeCount(vector<string>& words) {
    int cnt = N;

    for (string& word : words) {
        Node* curr = root->childs[word[0]];
        for (int i = 1; i < word.length() - 1; i++) {
            if (curr->childs.size() > 1)
                cnt++;
            curr = curr->childs[word[i]];
        }            
    }

    return cnt;
}

inline double solve() {
    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
        words[i] += " ";
    }

    initializeTree(words);

    int typeCount = calcTypeCount(words);

    freeMemory(root);

    return (double)typeCount / (double)N;
}