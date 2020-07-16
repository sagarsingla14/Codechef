#include <bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;

ld ans;
ll n;
vector <ll> graph[100001];
ll visited[100001];
ld degree[100001];
ll root;

void dfs(ll start , ll parent , ld num) {
    visited[start] = 1;
    if(start != root) {
        ans += num;
    }

    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i , start , (num / degree[start]));
        }
    }
}

void subtractDegree() {
    for(ll i = 2 ; i <= n - 1 ; i++) {
        degree[i] --;
    }
}

int main() {
    memset(visited , 0 , sizeof(visited));
    memset(degree , 0.0 , sizeof(degree));
    cin >> n;
    for(ll i = 0 ; i < n - 1 ; i++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u] ++;
        degree[v] ++;
    }

    ans = 0;
    root = 1;
    subtractDegree();
    dfs(1 , 1 , 1.0);

    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}
