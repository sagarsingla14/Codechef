#include <bits/stdc++.h>
using namespace std;

int t , n;
int graph[12][12];
int visited[12];
int ans;

void solve(int cur , int cost , int cnt) {
    if(cnt == n && graph[cur][0]) {
        ans = min(ans , graph[cur][0] + cost);
        return;
    }

    for(int i = 0 ; i < n ; i++) {
        if(!visited[i] && graph[cur][i]) {
            visited[i] = 1;
            solve(i , cost + graph[cur][i] , cnt + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> t;
    while(t--) {
        ans = 10000000000000;
        cin >> n;
        memset(graph , 0 , sizeof(graph));
        memset(visited , 0 , sizeof(visited));
        for(int i = 0 ; i < n ; i ++) {
            for(int j = 0 ; j < n ; j ++) {
                cin >> graph[i][j];
            }
        }
        visited[0] = 1;
        solve(0 , 0 , 1);
        cout << ans << endl;
    }
	return 0;
}
