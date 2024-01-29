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

int kmp(vector<int> v, string s, string sub){
    int i = 0;
    int j = 0;
    int cnt = 0;
    while(i<s.size()){
        if (s[i]==sub[j]){
            i++;
            j++;
            if(j == sub.size()){
                cnt++;
                j = 0;
            }
        }
        else{
            if (j>0){
                j = v[j-1];
            }
            else{
                i+=1;
            }
        }
    }
    return cnt;

}

int LPS(string hay, int m, string s) {
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    while (i < m) {
        if (s[i] == hay[len]) {
            lps[i] = len + 1;
            len++;
            i++;
        } else if (len != 0) {
            len = lps[len - 1];
        } else {
            i++;
        }
    }
    int res = lps[m - 1];
    return res;
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