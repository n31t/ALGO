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
    string v;
    int k;
    k = 0;
    int s;
    s = 0;
    cin >> v;
    while(true){
       for (int i = 0; i < n; i++) {
        if (v[i] == 'K') {
            if(s!=0){
                v[i] = 'o';
                s = s - 1;
                continue;
            }
            k++;
            if (v.find('S')==string::npos) {
                    printResult("KATSURAGI");
                    return 0;
                }
        }

        else if (v[i] == 'S') {
            if(k!=0){
                v[i] = 'o';
                k = k - 1;
                continue;
            }
            s++;

            if (v.find('K')==string::npos) {
                    printResult("SAKAYANAGI");
                    return 0;
                }
        }
        }
    }    
    return 0;
}