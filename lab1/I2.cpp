#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <string>
using namespace std;

void printResult(const string& result) {
    cout << result << endl;
}

int main() {
    int n;
    cin >> n;
    vector<char> v(n);
    stack<char> st;
    for (int i = 0; i < n; i++) {
        char a;
        cin >> a;
        v[i] = a;
    }
    while(true){
       for (int i = 0; i < n; i++) {
        if (v[i] == 'K') {
            for (int j = i + 1; j < n; j++) {
                if (v[j] == 'S') {
                    v[j] = 'o';
                    break;
                }
                else if (v.find('S')==npos) {
                    printResult("KATSURAGI");
                    return 0;
                }
            }
        }

        if (v[i] == 'S') {
            for (int j = i + 1; j < n; j++) {
                if (v[j] == 'K') {
                    v[j] = 'o';
                    break;
                }
                else if (v.find('K')==npos) {
                    printResult("SSS");
                    return 0;
                }
            }
        }
        }
    }
    
    return 0;
}