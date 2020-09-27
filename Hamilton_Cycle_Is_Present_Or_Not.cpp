#include <bits/stdc++.h>
using namespace std;

int t , n , m;
int graph[12][12];
int visited[12];
int ans;

bool solve(int cur , int cnt) {
    if(cnt == n && graph[cur][1]) {
        return true;
    }

    for(int i = 1 ; i <= n ; i++) {
        if(!visited[i] && graph[cur][i]) {
            visited[i] = 1;
            if(solve(i , cnt + 1)) {
                return true;
            }
            visited[i] = 0;
        }
    }

    return false;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;

        memset(graph , 0 , sizeof(graph));
        memset(visited , 0 , sizeof(visited));

        for(int i = 0 ; i < m ; i ++) {
            int x , y;
            cin >> x >> y;
            graph[x][y] = 1;
            graph[y][x] = 1;
        }

        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= n ; j++) {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }

        visited[1] = 1;
        bool ok = solve(1 , 1);

        if(ok) {
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
	return 0;
}
