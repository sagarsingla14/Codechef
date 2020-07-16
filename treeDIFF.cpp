#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll n;
ll mp[1000001];

void dfs(ll current , ll d , ll p , ll *depth , ll *parent , vector <ll> graph[]) {
    parent[current] = p;
    depth[current] = d;
    for(auto child : graph[current]) {
        if(child != p) {
            dfs(child , d + 1 , current , depth , parent , graph);
        }
    }
}


vector <ll> getpath(ll a , ll b , ll depth[] , ll parent[]) {
    vector <ll> path1;
    vector <ll> path2;
    path1.push_back(a);
    path2.push_back(b);
    while(a != b) {
        if(depth[a] > depth[b]) {
            a = parent[a];
            path1.push_back(a);
        }
        else if(depth[a] < depth[b]) {
            b = parent[b];
            path2.push_back(b);
        }
        else if(depth[a] == depth[b]) {
            a = parent[a];
            b = parent[b];
            path1.push_back(a);
            path2.push_back(b);
        }
    }

    reverse(path2.begin(), path2.end());
    path2.erase(path2.begin());
    path1.insert(path1.end(), path2.begin(), path2.end());

    return path1;
}

int main() {

    ll t;
    cin >> t;
    while(t--) {
        ll q;
        cin >> n >> q;

        ll arr[n + 1];
        for(ll i = 1 ; i <= n ; i++) {
            cin >> arr[i];
        }

        vector <ll> graph[n + 1];
        for(ll i = 0 ; i < n - 1 ; i++) {
            ll a , b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }


        ll depth[n + 1] = {0};
        ll parent[n + 1] = {0};
        dfs(1 , 0 , -1 , depth , parent , graph);

        while(q--) {
            ll u , v;
            cin >> u >> v;
            vector <ll> path;
            path = getpath(u , v , depth , parent);

            vector <ll> val;
            for(ll i = 0 ; i < path.size() ; i++) {
                val.push_back(arr[path[i]]);
            }
            sort(val.begin() , val.end());

            ll ans = 1e18;
            for(ll i = 1 ; i < val.size() ; i++) {
                ans = min(ans , abs(val[i] - val[i - 1]));
            }
            cout << ans << endl;
        }
    }
    return 0;
}
