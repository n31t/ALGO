#include <iostream>
#include <queue>

using namespace std;

int used[100][100];
int n;
int m;
int x;
int y;

struct vertex{
    vertex(int r, int c){
        this->r = r;
        this->c = c;
    }
    int r;
    int c;
};

queue<vertex> q;

void step(int r, int c, int t){
    if(r < n && c < m && used[r][c] == -1){
        used[r][c] = t;
        q.push(vertex(r, c));
    }
}

void print(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << used[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
}


int main(){
 
    cin >> n >> m;
    cin >> x >> y;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            used[i][j] = -1;
        }
    }

    q.push(vertex(x, y));
    used[x][y] = 0;


    print();

    while(q.size() > 0){
        vertex cur = q.front();
        q.pop();
        step(cur.r + 1, cur.c, used[cur.r][cur.c] + 1);
        step(cur.r - 1, cur.c, used[cur.r][cur.c] + 1);
        step(cur.r, cur.c + 1, used[cur.r][cur.c] + 1);
        step(cur.r, cur.c - 1, used[cur.r][cur.c] + 1);
        print();
    }

    int mmax = -1;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(used[i][j] > mmax){
                mmax = used[i][j];
            }
        }
    }

    cout << mmax;

   
    return 0;
}