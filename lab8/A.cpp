#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
using namespace std;

long long mod = 1e9 + 7;
long long p = 11;

string hash1(string s) {
    long long h = 0;
    for (long long i = s.size() - 1; i >= 0; i--) {
        h = (h * p % mod + (s[i] - 47)) % mod;
    }
    return to_string(h);
}
void print(string key, string hash){
    cout<< "Hash of string \"" + key + "\" is " + hash << endl;
}
int main(){
    long long int n;
    cin>>n;
    vector<string> v;
    unordered_set<string> hashSet;
    pair<string,string> p[2*n];
    string s;
    for(long long int i=0; i<2*n;i++){     
        cin>>s;
        v.push_back(s);
        p[i].first = s;
        p[i].second = hash1(s);

    }
    // int i=0;
    long long int fix = v.size();
    for(long long int i = 0 ; i < 2 * n ;i++){
        for(long long int j = 0; j < fix;j++){
            if(p[i].second == v[j]){
                v.erase(v.begin() + j);
                for(int k = 0; k < fix;k++){
                    if(p[i].first == v[k]){
                    v.erase(v.begin() + k);
                    fix = fix - 1;
                    break;
                    }
                }
                print(p[i].first, p[i].second);
                fix = fix - 1;
                break;
            }
        }
    }
    // while(v.size()!=0){ 
    //     int fix2 = 0;       
    //     for(int j=0; j<fix;j++){
    //         if(hash1(v[i])==v[j]){
    //             print(v[i], v[j]);
    //             if(i<j){
    //                 v.erase(v.begin()+j);
    //                 v.erase(v.begin()+i);
    //                 i=-1;
    //                 fix-=2;
    //                 fix2 = 1;
    //                 break;
    //             }
    //             else{
    //                 v.erase(v.begin()+i);
    //                 v.erase(v.begin()+j);
    //                 i=-1;
    //                 fix-=2;
    //                 fix2 = 1;
    //                 break;
    //             }
    //         }
    //     }
    //     if(fix2 == 0){
    //       i++;
    //       if(i==v.size() or i>v.size()){
    //         i = 0;
    //       }  
    //     }
    //     else{
    //       i = 0;  
    //     }
    //}
}
// 3
// 13903
// 3383080447314675044643313
// 9839
// 813695185
// 425675346
// 3461762860035486