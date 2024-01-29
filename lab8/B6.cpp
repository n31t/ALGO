#include <iostream>
#include <vector>

using namespace std;

int get_hash(char a) {
    return a - 'a' + 1;
}

int sum(const vector<int>& v, int st, int end) {
    int s = 0;
    for (int i = st; i < end; i++) {
        s += v[i];
    }
    return s;
}

int main() {
    string s, s2, targetString;
    cin >> s >> s2 >> targetString;
    int targetHash = 0;
    vector<int> sHash(s.size());
    vector<int> s2Hash(s2.size());

    for (int i = 0; i < targetString.size(); i++) {
        targetHash += get_hash(targetString[i]);
    }

    for (int i = 0; i < s.size(); i++) {
        sHash[i] = get_hash(s[i]);
        s2Hash[i] = get_hash(s2[i]);
    }

    int cnt = 0;
    for (int i = 0; i <= s.size() - targetString.size(); i++) {
        if (sum(sHash, i, i + targetString.size()) == targetHash &&
            sum(s2Hash, i, i + targetString.size()) == targetHash &&
            s.substr(i, targetString.size()) == targetString &&
            s2.substr(i, targetString.size()) == targetString) {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
