#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

int foundTimes(vector<int> v, string s){
    int k = 0;
    for(int i = 0; i < v.size();i++){
        if(v[i] == s.size()){
            k++;
        }
    }
    return k;
}

vector<int> foundIn(vector<int> v, string s){
    vector<int> a;
    int b;
    for(int i = 0; i < v.size();i++){
        if(v[i] == s.size()){
            b = i - (2 * s.size()) + 1;
            a.push_back(b);
        }
    }
    return a;
}

int main(){
    string s,s2, pod;
    cin >> s;
    s2 = s;
    cin >> pod;
    vector<int> v;
    string temp;
    int chetchik = 0;
    int k;
    while (s2.size() < pod.size()) {
        s2 += s;
        chetchik++;
    }
    while(true){
        chetchik++;
        temp = pod + '#' + s2;
        v = prefix_function(temp);
        k = foundTimes(v, pod);
        if(k > 0){
            cout << chetchik;
            return 0;
        }
        else if( s2.size() < pod.size() * 2){
            s2 = s2 + s;
        }
        else {
            break;
        }
    }
    cout << -1;
    return 0;
}