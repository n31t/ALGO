#include <iostream>
#include <cmath>
#include <vector>

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

vector<int> nthPrime(int n) {
    if (n <= 0) {
        return vector<int>(); 
    }
    
    vector<int> primes;
    int count = 0;
    int num = 2;
    while (count < n) {
        if (isPrime(num)) {
            primes.push_back(num);
            count++;
        }
        num++;
    }
    return primes;
}

int main() {
    int n;
    cin >> n;
    vector<int> result = nthPrime(n);
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    cout << endl;
    return 0;
}




