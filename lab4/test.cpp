#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v;
    int a;
    for(int i = 0; i < n;i++){
        cin >> a;
        v.push_back(a);
    }

    return 0;
}