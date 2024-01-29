#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
int a[200][200];

int bfs(int a, int b){
    if(a == b){
        return 0;
    }
    queue<int> q;
    q.push(a);
    int distance = 0;
    while(true){
        int current = q.front();
        q.pop();
        if(current == b){
            return 1;
        }
        int number_one = current * 2;
        q.push(number_one);
        int number_two = current - 1;
        q.push(number_two);
    }
}

int main() {
    int a,b;
    cin >> a >> b;
    int result;
    cout << bfs(a,b);
}
