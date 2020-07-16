#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , m , t;

vector <ll> component;
void dfs(ll start , ll mp[] , vector <ll> graph[] , ll visited[]) {
    visited[start] = 1;
    component.push_back(start);
    for(auto i : graph[start]) {
        if(mp[i] && !visited[i]) {
            dfs(i , mp , graph , visited);
        }
    }
}

int main() {
    fast_io

    cin >> t;
    while (t--) {

        cin >> n >> m;

        ld arr[n + 1] = {0};
        ld p[n + 1] = {0};

        for(ll i = 1 ; i <= n ; i++) {
            cin >> arr[i];
        }
        for(ll i = 1 ; i <= n ; i++) {
            cin >> p[i];
        }

        vector <ll> graph[n + 1];
        ll visited[n + 1] = {0};

        for(ll i = 0 ; i < m ; i++) {
            ll u , v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector <pair <ll , ld> > v;

        ld mx = 0;
        for(ll i = 1 ; i <= n ; i++) {
            ld val = arr[i] / p[i];
            v.push_back({i , val});
            mx = max(mx , val);
        }

        ll mp[n + 1] = {0};
        vector <ll> nodes;
        for(ll i = 0 ; i < n ; i++) {
            if(v[i].second == mx) {
                mp[v[i].first] = 1;
                nodes.push_back(v[i].first);
            }
        }

        vector <vector <ll> > ans;

        for(auto i : nodes) {
            if(!visited[i]) {
                component.clear();
                dfs(i , mp , graph , visited);
                ans.push_back(component);
            }
        }

        ll sze = ans.size();
        ll terms = 0;
        ll index = -1;

        for(ll i = 0 ; i < sze ; i++) {
            ll ss = ans[i].size();
            if(ss > terms) {
                terms = ss;
                index = i;
            }
        }

        cout << ans[index].size() << endl;
        for(ll i = 0 ; i < ans[index].size() ; i++) {
            cout << ans[index][i] << " ";
        }
        cout << endl;

    }
    return 0;
}
