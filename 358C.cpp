// DFS + Kadane's Algorithm
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1e18

ll n , ans;
ll visited[100001];
ll level[100001];
ll degree[100001];
ll sum[100001];
ll arr[100001];
map <pair <ll , ll> , ll> mp;
vector <ll> graph[100001];

void dfs(ll start , ll parent , ll remove) {
    visited[start] = 1;
    for(auto i : graph[start]) {
        if(!visited[i] && i != parent) {
            if(remove == 1) {
                sum[i] = MAX;
                dfs(i , start , 1);
            }
            else{
                ll u = start;
                ll v = i;
                ll w = 0;
                if(mp.find({u , v}) != mp.end()) {
                    w = mp[{u  , v}];
                }
                sum[v] = max(sum[u] + w , 0ll);
                if(sum[v] > arr[v]) {
                    sum[v] = MAX;
                    dfs(i , start , 1);
                }
                else{
                    dfs(i , start , 0);
                }
            }
        }
    }
}

int main() {
    cin >> n;

    memset(visited , 0 , sizeof(visited));
    memset(degree , 0 , sizeof(degree));
    memset(level , 0 , sizeof(level));
    memset(sum , 0 , sizeof(sum));

    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }

    for(ll i = 1 ; i <= n - 1 ; i++) {
        ll u , w;
        cin >> u >> w;
        graph[u].push_back(i + 1);
        graph[i + 1].push_back(u);
        mp[{i + 1 , u}] = w;
        mp[{u , i + 1}] = w;
    }

    dfs(1 , 1 , 0);

    ans = 0;
    for(ll i = 1 ; i <= n ; i++) {
        if(sum[i] == MAX) {
            ans ++;
        }
    }

    cout << ans << endl;
    return 0;
}
