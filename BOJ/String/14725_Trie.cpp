#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string value;
    vector<Node*> childs;

    Node(string value): value(value) {}
};

int N, K;
Node root("");

inline void insert(vector<string>& values);
void traversal(Node* root, int depth);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while (N--) {
        cin >> K;
        vector<string> values(K);
        for (int i = 0; i < K; i++)
            cin >> values[i];
        insert(values);
    }

    traversal(&root, 0);

    return 0;
}

inline void insert(vector<string>& values) {
    Node* curr = &root;
    for (int i = 0; i < values.size(); i++) {
        bool found = false;
        for (Node* child : curr->childs)
            if (child->value == values[i]) {
                curr = child;
                found = true;
                break;
            }

        if (!found) {
            Node* newNode = new Node(values[i]);
            curr->childs.push_back(newNode);
            curr = newNode;
        }
    }
}

inline void traversal(Node* root, int depth) {
    vector<pair<string, Node*>> sortedChilds;
    for (Node* child : root->childs)
        sortedChilds.push_back({ child->value, child });
    sort(sortedChilds.begin(), sortedChilds.end());

    for (pair<string, Node*>& p : sortedChilds) {
        cout << string(depth * 2, '-');
        cout << p.first << '\n';
        traversal(p.second, depth + 1);
    }
}