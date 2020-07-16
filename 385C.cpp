#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 100000000000000

ll n , m , k , cnt = 0 , u , v , ans = 0;
vector <ll> graph[1001];
vector <ll> visited(1001 , 0);
ll arr[1001] = {0};

void dfs(ll start) {
    visited[start] = 1;
    cnt ++;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for(ll i = 0 ; i < k ; i++) {
        cin >> arr[i];
    }
    for(ll i = 0 ; i < m ; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ll mx = 0;
    for(ll i = 0 ; i < k ; i++) {
        if(!visited[arr[i]]) {
            cnt = 0;
            dfs(arr[i]);
            ans += ((cnt) * (cnt - 1)) / 2;
            mx = max(mx , cnt);
        }
    }

    cnt = 0;
    for(ll i = 1 ; i <= n ; i++) {
        if(!visited[i]) {
            cnt ++;
        }
    }

    ans += mx * cnt;
    ans += (cnt * (cnt - 1)) / 2;
    ans -= m;
    cout << ans << endl;

    return 0;
}
