#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector <ll> graph[100001];
ll visited[100001];
ll dp[100001];
ll  n , m;

void dfs(ll start) {
    visited[start] = 1;
    dp[start] = 1;

    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i);
            dp[start] += dp[i];
        }
    }
}

int main() {
    cin >> n >> m;

    memset(visited , 0 , sizeof(visited));
    memset(dp , 0 , sizeof(dp));

    for(ll i = 0 ; i < m ; i++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    vector <pair <ll , pair <ll , ll>>> ans;
    ll total = (n * (n - 1)) / 2;

    for(ll start = 1 ; start <= n ; start++) {
        for(auto i : graph[start]) {
            ll left = dp[i];
            ll right = n - dp[i];

            left = (left * (left - 1)) / 2;
            right = (right * (right - 1)) / 2;

            ans.push_back({(left + right) , {start , i}});
        }
    }

    sort(ans.begin() , ans.end());

    ll mx = ans[0].first;

    vector <pair <ll , ll>> selectFinal;
    for(ll i = 0 ; i < ans.size() ; i++) {
        if(mx != ans[i].first) {
            break;
        }
        else{
            selectFinal.push_back({ans[i].second.first , ans[i].second.second});
        }
    }

    sort(selectFinal.begin() , selectFinal.end());
    cout << selectFinal[0].first << " " << selectFinal[0].second << endl;

    return 0;
}
