#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
#include <cmath>
using namespace std;

int p = 31;
const long long q = INT_MAX;

int get_hash(string s) {
    int h = 0;
    for (int i = 0; i < s.size(); i++) {
        h = (h * p + (s[i] - 'a' + 1)) % q;
    }
    return h;
}

set<int> substrCnt(string s){
    set<int> hashSet;
    int str_size = s.size();

    for (int substr_size = 1; substr_size <= str_size; substr_size++) {
        int h = 0;
        h = get_hash(s.substr(0, substr_size));

        for (int j = 1; j <= str_size - substr_size + 1; j++) {
            h = get_hash(s.substr(j, substr_size));
            hashSet.insert(h);
        }
    }

    return hashSet;
}

int main() {
    string s; 
    cin >> s;
    set<int> hashSet = substrCnt(s);
    cout << hashSet.size();
    return 0;
}
