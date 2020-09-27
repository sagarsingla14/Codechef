#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int u , v;

void solve(int cur , vector <int> graph[] , int visited[])  {
    visited[cur] = 1;
    for(auto itr : graph[cur]) {
        if(!visited[itr]) {
            solve(itr , graph , visited);
        }
    }
}

void plag() {
    for(int i = 0 ; i < 5 ; i++) ;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        plag();

        ans = 0;

        int dig[n + 1] = {0};
        int visited[10001] = {0};
        vector <int> graph[10001];

        for(int i = 0 ; i < n - 1 ; i++) {
            cin >> u >> v;
            dig[v] ++;
            graph[u].push_back(v);
        }

        for(int i = 1 ; i <= n ; i++) {
            if(dig[i] == 0) {
                if(!visited[i]) {
                    ans ++;
                    solve(i , graph , visited);
                }
            }
        }
        ans --;
        cout << ans << endl;
    }
    return 0;
}
