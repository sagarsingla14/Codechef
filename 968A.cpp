#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 100000000000000

ll n , m , k , s;
vector <ll> graph[100001];
vector <ll> dist[100001];
ll arr[100001] = {0};
ll dp[100001] = {0};
ll visited[100001] = {0};
queue <ll> q;

void bfs() {
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
    ll d[2][2][2];
    memset(d , 0 , sizeof(d));
    cout << d[1][-1][-1] << endl;

    cin >> n >> m >> k >> s;
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }



    for(ll i = 0 ; i < m ; i++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(ll i = 1 ; i <= k ; i++) {
        memset(visited , 0 , sizeof(visited));
        for(ll j = 1 ; j <= n ; j++) {
            if(arr[j] == i) {
                dp[j] = 0;
                visited[j] = 1;
                q.push(j);
            }
        }
        bfs();
        for(ll j = 1 ; j <= n ; j++) {
            dist[j].push_back(dp[j]);
        }
    }

    for(ll i = 1 ; i <= n ; i++) {
        sort(dist[i].begin() , dist[i].end());
        ll cnt = 0;
        for(ll j = 0 ; j < s ; j++) {
            cnt += dist[i][j];
        }
        cout << cnt << " ";
    }
    cout << endl;
    return 0;
}
