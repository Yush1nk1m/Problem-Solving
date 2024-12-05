#include <bits/stdc++.h>
using namespace std;

class Code {
public:
    string content;
    bool operator<(const Code& other) const {
        if (content.length() == other.content.length()) {
            int lsum = 0, rsum = 0;
            for (char c : content)
                if ('0' <= c && c <= '9')
                    lsum += c - '0';
            for (char c : other.content)
                if ('0' <= c && c <= '9')
                    rsum += c - '0';
            if (lsum == rsum) {
                return content < other.content;
            }
            return lsum < rsum;
        }
        return content.length() < other.content.length();
    }
    Code(string content): content(content) {}
};

int N;
vector<Code> codes;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while (N--) {
        string content;
        cin >> content;
        codes.push_back(Code(content));
    }
    sort(codes.begin(), codes.end());

    for (Code& code : codes)
        cout << code.content << '\n';

    return 0;
}