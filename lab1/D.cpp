#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    string str;
    cin >> str;
    if(str.size()%2==1){
        cout << "NO";
        return 0;
    }
    for(int i = 0; i < str.size(); i++){
        for(int j = i+1; j < str.size(); j++){
            if( str[i] == 0 ){
                break;
            }
            if( str[i] == str[j] && ((j - i) % 2 == 1 )){
                str[i] = 0;
                str[j] = 0;
                break;
            }
        }
    }
    bool is_okay = true;
    for(int i = 0; i < str.size();i++){
        if( str[i] != 0){
            is_okay = false;
        }
    }
    if(is_okay){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}