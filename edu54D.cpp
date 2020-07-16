#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INF 10000000000000

ll n , m , k , cnt = 0;

void dijkstra(ll s , vector <ll> &dp , ll parent[] , ll visited[] , vector <pair <ll , ll>> graph[]) {
    dp[0] = 0;
    dp[1] = 0;
    priority_queue <pair <ll , ll> , vector <pair <ll , ll>> , greater <pair <ll , ll>>> pq;
    pq.push({0 , s});

    visited[s] = 1;
    parent[1] = 1;
    while(!pq.empty() && cnt <= k) {
        ll node = pq.top().second;
        ll weight = pq.top().first;
        pq.pop();
        cnt ++;
        visited[node] = 1;
        for(auto i : graph[node]) {
            if(!visited[i.first] && dp[i.first] > weight + i.second) {
                parent[i.first] = node;
                dp[i.first] = weight + i.second;
                pq.push({dp[i.first] , i.first});
            }
        }
    }
}

void formMst(ll parent[] , ll visited[] , vector <pair <ll , ll>> mst[]) {

    for(ll i = 1 ; i <= n ; i++) {
        mst[i].clear();
    }
    for(ll i = n ; i >= 2 ; i--) {
        if(!visited[i]) {
            ll cur = i;
            while(parent[cur] != 1) {
                visited[cur] = 1;
                ll par = parent[cur];
                mst[par].push_back({cur , 1});
                mst[cur].push_back({par , 1});
                cur = par;
            }
            mst[1].push_back({cur , 1});
            mst[cur].push_back({1 , 1});
            visited[cur] = 1;
        }
    }
}

void dfs(ll node , ll visited[] , vector <pair <ll , ll>> mst[] , vector <ll> &ans , map <pair <ll , ll> , ll> &mp) {
    visited[node] = 1;
    for(auto i : mst[node]) {
        if(!visited[i.first] && ans.size() < k) {
            if(mp[{node , i.first}]) {
                ans.push_back(mp[{node , i.first}]);
            }
            else{
                ans.push_back(mp[{i.first , node}]);
            }
            dfs(i.first , visited , mst , ans , mp);
        }
    }
}

int main() {
    fast_io
    cin >> n >> m >> k;

    vector <pair <ll , ll>> graph[n + 1];
    map <pair <ll , ll> , ll> mp;

    for(ll i = 0 ; i < m ; i++) {
        ll u , v , w;
        cin >> u >> v >> w;
        graph[u].push_back({v , w});
        graph[v].push_back({u , w});
        mp[{u , v}] = i + 1;
        mp[{v , u}] = i + 1;
    }

    ll visited[n + 1] = {0};
    ll parent[n + 1] = {0};

    vector <ll> dp(n + 1 , INF);
    dijkstra(1 , dp , parent , visited , graph);

    memset(visited , 0 , sizeof(visited));
    formMst(parent , visited , graph);

    memset(visited , 0 , sizeof(visited));

    vector <ll> ans;
    dfs(1 , visited , graph , ans , mp);

    cout << ans.size() << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
