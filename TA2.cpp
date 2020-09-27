#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

vector <ll> graph[100001];
ll degree[100001];
ll visited[100001];
vector <ll> component;
ll n , m;

void dfs(ll start) {
    visited[start] = 1;
    component.push_back(start);
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    cin >> n >> m;
    memset(visited , 0 , sizeof(visited));
    memset(degree , 0 , sizeof(degree));

    for(ll i = 0 ; i < m ; i++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u] ++;
        degree[v] ++;
    }

    ll ans = 0;

    for(ll i = 1 ; i <= n ; i++) {
        if(!visited[i]) {
            component.clear();
            dfs(i);
            ll nodes = component.size();
            ll degreeSum = 0;
            for(auto itr : component) {
                degreeSum += degree[itr];
            }
            degreeSum /= 2;
            ans += (degreeSum - (nodes - 1));
        }
    }

    cout << ans << endl;
    return 0;
}
