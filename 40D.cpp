#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define INF 1000000000000000000
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector <ll> graph[1001];
ll visited[1001] = {0};
ll n , m , s , t , l = 0 , ans = 0;
map <pair <ll , ll> , ll> mp;

void bfs(ll start , ll dp[]) {
    visited[start] = 1;
    queue <ll> q;
    q.push(start);
    while(!q.empty()) {
        ll val = q.front();
        q.pop();

        for(auto i : graph[val]) {
            if(!visited[i]) {
                dp[i] = dp[val] + 1;
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    fast_io
    cin >> n >> m >> s >> t;
    for(ll i = 0 ; i < m ; i++) {
        ll u , v;
        cin >> u >> v;
        mp[{u , v}] = 1;
        mp[{v , u}] = 1;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ll ds[n + 1] = {0};
    ll dt[n + 1] = {0};

    memset(visited , 0 , sizeof(visited));
    bfs(s , ds);

    memset(visited , 0 , sizeof(visited));
    bfs(t , dt);

    ll sd = ds[t];
    for(ll i = 1 ; i <=  n ; i++) {
        for(ll j = i ; j <= n ; j++) {
            if(i != j && !mp[{i , j}]) {
                if(dt[i] + ds[j] + 1 >= sd && dt[j] + ds[i] + 1 >= sd) {
                    ans ++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
