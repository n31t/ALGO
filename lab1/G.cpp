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

int nthPrime(int n) {
    if (n <= 0) {
        return 0;  
    }
    
    int count = 0;
    int num2 = 0;
    int num = 2;
    while (count < n) {
        if (isPrime(num)) {
            num2++;
            if(isPrime(num2)){
                count++;
            }           
        }
        if (count == n) {
            return num;
        }
        num++;
    }
    return 0;  
}

int main() {
    int n;
    cin >> n;
    int result = nthPrime(n);
    cout << result << endl;
    return 0;
}