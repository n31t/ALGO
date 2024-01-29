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
    string s, pod;
    cin >> s;
    cin >> pod;
    vector<int> v;
    s = pod + '#' + s;
    v = prefix_function(s);
    v = foundIn(v, pod);
    cout << v.size() << endl;
    for(int i = 0; i < v.size();i++){
        cout << v[i] << ' ';
    }
    return 0;
}