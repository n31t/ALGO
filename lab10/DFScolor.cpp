#include <iostream>

using namespace std;

int a[100][100];
int color[100];
int n;

void dfs(int v){
    cout << v + 1<< endl;
    color[v] = 1;
    for(int i = 0; i < n; ++i){
        if(color[i] == 0 && a[v][i] != 0){
            dfs(i);
        }
    }
    color[v] = 2;
}

int main(){
 
    cin >> n;

    for(int i = 0; i < n; ++i){
        color[i] = 0;
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }

    dfs(0);

    return 0;
}