#include <iostream>
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

int main(){
    int n;
    string s, pod;
    cin >> pod;
    cin >> n;
    cin >> s;
    int k;
    vector<int> v;
    string temp;
    while(true){
        temp = pod + '#' + s;
        v = prefix_function(temp);
        k = foundTimes(v, pod);
        if(k>0){
            cout << k;
            break;
        }
        else if(s.size() < 2* pod.size()){
            s = s + s;
        }
    }
    
    return 0;
}