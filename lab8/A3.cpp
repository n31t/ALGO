#include <iostream>
#include <cmath>
#include <vector>
#include <set>
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
    set<string> set;
    pair<string,string> p[2*n];
    string s;
    for(long long int i=0; i<2*n;i++){     
        cin>>s;
        set.insert(s);
        p[i].first = s;
        p[i].second = hash1(s);

    }
    for(long long int i = 0 ; i < 2 * n ;i++){
        for(long long int j = 0; j < set.size();j++){
            if(set.find(p[i].second!= set.end())){
                set.erase(s.find(p[i].second));
                print(p[i].first, p[i].second);
                break;
            }
        }
    }
}