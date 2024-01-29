#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    if (num % 2 == 0) {
        return false;
    }
    int sqrtNum = static_cast<int>(sqrt(num));
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
int main(){
    int a;
    cin >> a;
    if(isPrime(a)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}