#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

vector<int> karp(const string& t1, const string& t2, const string& s) {
    vector<int> positions;
    const long long q = INT_MAX;
    long long p[max(t1.size(), t2.size())];
    long long h1[max(t1.size(), t2.size())];
    long long h2[max(t1.size(), t2.size())];
    p[0] = 1;

    for (int i = 1; i < max(t1.size(), t2.size()); ++i) {
        p[i] = (p[i - 1] * 31) % q;
    }

    h1[0] = t1[0] - 'a' + 1;
    for (int i = 1; i < t1.size(); ++i) {
        h1[i] = (h1[i - 1] + (((t1[i] - 'a' + 1) * p[i]) % q + q) % q) % q;
    }

    h2[0] = t2[0] - 'a' + 1;
    for (int i = 1; i < t2.size(); ++i) {
        h2[i] = (h2[i - 1] + (((t2[i] - 'a' + 1) * p[i]) % q + q) % q) % q;
    }

    long long h_s = 0;
    for (int i = 0; i < s.size(); ++i) {
        h_s = (h_s + (((s[i] - 'a' + 1) * p[i]) % q + q) % q) % q;
    }

    for (int i = 0; i < max(t1.size(), t2.size()) - s.size() + 1; ++i) {
        long long temp1 = h1[i + s.size() - 1];
        long long temp2 = h2[i + s.size() - 1];

        if (i > 0) {
            temp1 -= h1[i - 1];
            temp2 -= h2[i - 1];

            if (temp1 < 0) {
                temp1 += q;
            }
            if (temp2 < 0) {
                temp2 += q;
            }
        }

        if ((temp1 == (h_s * p[i]) % q) && (temp2 == (h_s * p[i]) % q)) {
            bool match = true;
            for (int j = 0; j < s.size(); ++j) {
                if (t1[i + j] != s[j] || t2[i + j] != s[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                positions.push_back(i);
            }
        }
    }

    return positions;
}

int main() {
    string t1, t2, s;
    cin >> t1 >> t2 >> s;
    vector<int> positions = karp(t1, t2, s);
    cout << positions.size();

    return 0;
}
