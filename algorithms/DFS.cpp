int a[100][100];
bool used[100];
int n;

void dfs(int v){
    cout << v + 1<< endl;
    used[v] = true;
    for(int i = 0; i < n; ++i){
        if(!used[i] && a[v][i] != 0){
            dfs(i);
        }
    }
}