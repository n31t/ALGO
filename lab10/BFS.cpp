#include <iostream>
#include <queue>

using namespace std;

int a[100][100];
bool used[100];
int n;


int main(){
 
    cin >> n;

    queue<int> q;

    for(int i = 0; i < n; ++i){
        used[i] = false;
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }

    q.push(0);
    used[0] = true;

    while(q.size() > 0){
        int cur = q.front();
        cout << cur + 1<< " ";
        q.pop();
        for(int i = 0; i < n; ++i){
            if(!used[i] && a[cur][i] > 0){
                q.push(i);
                used[i] = true;
            }
        }
    }

   
    return 0;
}