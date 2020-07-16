#include <bits/stdc++.h>
#define ll long long int
using namespace std;


ll n , m;
ll visited[500001];
ll level[500001];
ll degree[500001];
vector <ll> graph[500001];
ll ans;

void setLevel(ll start , ll curlevel) {
    visited[start] = 1;
    level[start] = curlevel;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            setLevel(i , curlevel + 1);
        }
    }
}

int main() {
    memset(visited , 0 , sizeof(visited));
    memset(degree , 0 , sizeof(degree));
    memset(level , 0 , sizeof(level));

    ll n;
    cin >> n;
    for(ll i = 2 ; i <= n ; i++) {
        ll u;
        cin >> u;
        graph[u].push_back(i);
        degree[u] ++;
    }

    setLevel(1 , 1);

    map <ll , ll> mp;
    for(ll i = 1 ; i <= n ; i++) {
        ll l = level[i];
        mp[l] += degree[i];
    }

    for(auto i : mp) {
        if(i.second % 2) {
            ans ++;
        }
    }

    ans ++;

    cout << ans << endl;
    return 0;
}
