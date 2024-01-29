#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

string hash1(string s) {
    long long int h = 0, q = (pow(10, 9) + 7);
    for (long long int i = 0; i < s.size(); i++) {
        long long int p = pow(11, i);
        h = h % q + (((int(s[i]) - 47) * p) % q);
    }
    h = h % q;
    return to_string(h);
}

void print(string key, string hash) {
    cout << "Hash of string \"" + key + "\" is " + hash << endl;
}

int main() {
    int n;
    cin >> n;
    vector<string> v;
    string s;
    for (long long int i = 0; i < 2 * n; i++) {
        cin >> s;
        v.push_back(s);
    }

    int i = 0;
    while (v.size() != 0) {
        for (int j = i + 1; j < v.size(); j++) {
            if (hash1(v[i]) == v[j]) {
                print(v[i], v[j]);
                v.erase(v.begin() + j);
                v.erase(v.begin() + i);
                i = -1;  // Resetting to start over after modification
                break;
            }
        }
        i++;
        if (i >= v.size()) {
            break;  // Avoid going out of bounds
        }
    }

    return 0;
}
