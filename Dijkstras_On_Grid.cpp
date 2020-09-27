#include <bits/stdc++.h>
using namespace std;

int n , t;
int graph[100][100];
int visited[100][100];
int dp[100][100];

int dx[4] = {0, 0 , 1 , -1};
int dy[4] = {1 , -1 , 0 , 0};

bool isValid(int x , int y) {
    if(x >= 0 && x < n && y >= 0 && y < n) {
        return true;
    }
    return false;
}

void Dijkstra() {
    priority_queue <pair <int , pair <int , int>> , vector <pair <int , pair <int , int>>> , greater <pair <int , pair <int , int>>>> pq;
    pq.push({graph[0][0] , {0 , 0}});

    dp[0][0] = graph[0][0];

    while(!pq.empty()) {
        pair <int , pair <int , int>> cur = pq.top();
        pq.pop();

        int x = cur.second.first;
        int y = cur.second.second;

        if(visited[x][y]) {
            continue;
        }

        visited[x][y] = 1;

        for(int i = 0 ; i < 4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isValid(nx , ny) && !visited[nx][ny]) {
                if(graph[nx][ny] + dp[x][y] < dp[nx][ny]) {
                    dp[nx][ny] = graph[nx][ny] + dp[x][y];
                    pq.push({dp[nx][ny] , {nx , ny}});
                }
            }
        }
    }
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                cin >> graph[i][j];
            }
        }

        memset(visited , 0 , sizeof(visited));
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                dp[i][j] = INT_MAX;
            }
        }

        Dijkstra();

        cout << dp[n - 1][n - 1] << endl;
    }
    return 0;
}
