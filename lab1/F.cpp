#include <iostream>
#include <stack>
#include <vector>
using namespace std;
 
int Prime(int n)
{
    int k,k2,number;
    k = 0;
    k2 = 0;
    for(int i = 2; k < n;i++){
        k2 = 0;
        for(int j = 1; j < i+1;j++){
            if(i%j==0){
                k2 += 1;
                number = j;
            }
        }
        if(k2==2){
            k +=1;
        }
    }
    return number;
}
 
int main()
{
    int n;
    cin >> n;
    Prime(n);
    cout << n;
    return 0;
}