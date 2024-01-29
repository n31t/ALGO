#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int bfs(vector <vector <int> > &adj, int start, int end) {
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> distance(n, INT_MAX);

    queue<int> q;
    q.push(start);
    visited[start] = true;
    distance[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor = 0; neighbor < n; ++neighbor) {
            if (adj[current][neighbor] == 1 && !visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                distance[neighbor] = distance[current] + 1;

                if (neighbor == end) {
                    return distance[neighbor];
                }
            }
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int> > adj(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }

    int start, end;
    cin >> start >> end;

    int result = bfs(adj, start - 1, end - 1);

    cout << result << endl;

    return 0;
}
