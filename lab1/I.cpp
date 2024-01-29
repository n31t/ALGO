#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int n;
    vector<char> v(n);
    cin >> n;
    for(int i = 0; i < n;i++) {
        char a;
        cin >> a;
        v[i] = a;
    }
    for(int i = 0; i < n; i++){
        if(v[i] == 'K'){
            for(int j = i+1; j < n; j++)
            {
            if(v[j] == 'S'){ 
                v[j] = 'o';
                break;
                }
            else if(j+1==n){
                
                cout << "KATSURAGI";
                return 0;
            }
            }
            }

        if(v[i] == 'S'){
            for(int j = i+1; j < n; j++)
            {
            if(v[j] == 'K'){ 
                v[j] = 'o';
                break;
                }
            else if(j+1==n){
                cout << "SSS";
                return 0;
            }
            }
            }
        
    }
}