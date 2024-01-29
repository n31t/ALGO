#include <iostream>
#include <cmath>
using namespace std;

string hash1(string s) {
    long long int h = 0, q = (pow(10, 9) + 7);
    for (long long int i = 0; i < s.size(); i++) {
        long long int p = pow(11, i);
        h = (h * 11 + (int(s[i]) - 47)) % q;
    }
    h = (h + q) % q;  // Ensure the result is non-negative
    return to_string(h);
}

int main() {
    string s = "3383080447314675044643313";
    cout << "Hash code for " << s << ": " << hash1(s) << endl;

    return 0;
}
