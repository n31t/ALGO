// #include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
  stack<char> s1;
  stack<char> s2;
  vector<char> v1;
  vector<char> v2;
  string str;
  cin >> str;
  for (int i = 0; i < str.size();i++){
    if(str[i]=='#'){
        s1.pop();
    }
    else{
    s1.push(str[i]);
    }
  }
  cin >> str;
  for (int i = 0; i < str.size();i++){
    if(str[i]=='#'){
        s2.pop();
    }
    else{
        s2.push(str[i]);
    }
  }

//    while (!s1.empty()) {
//         cout << s1.top();
//         s1.pop();
//     }
//     cout << ' ';
//     while (!s2.empty()) {
//         cout << s2.top();
//         s2.pop();
//     }
    int k = 0;
    if (s1.size()==0 or s2.size()==0){
        k = -1;
    }
    if (s1.size()==0 and s2.size()==0){
        k = 0;
    }
    while (!s1.empty() && !s2.empty()){
        if(s1.size()!=s2.size() or s1.top()!=s2.top()){
            k = -1;
            break;
        }
        s1.pop();
        s2.pop();
    }
    if (k == 0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
  return 0;
}