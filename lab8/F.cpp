#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

int p = 31;
const long long q = INT_MAX;

int get_hash(string s) {
    int h = 0;
    for (int i = 0; i < s.size(); i++) {
        h = ((h * p)%q + (s[i] - 'a' + 1)) % q;
    }
    return h;
}

set<long long int> substrCnt(string s){
    set<long long  int> set;
    int str_size, substr_size; 
    str_size = s.size();
    substr_size = 0;
    long long int h = 0;
    for(int i = 0; i < str_size;i++){
        substr_size++;
        // h = get_hash(s.substr(0, substr_size));
        for(int j = 0; j < str_size - substr_size + 1;j++){
            h = get_hash(s.substr(j, substr_size));
            set.insert(h);
        }
    }
    return set;
}

int main() {
    string s; 
    cin >> s;
    set<long long  int> set = substrCnt(s);
    cout << set.size();
    return 0;
}
