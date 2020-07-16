#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n, m;
vector <ll> graph[100001];
ll visited[100001];
ll d[100001];

void dfs(ll start , ll level) {
    visited[start] = 1;
    d[start] = level;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i , d[start] + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(visited , 0 , sizeof(visited));
    memset(d , 0 , sizeof(d));

    cin >> n >> m;
	for(ll i = 0 ; i < n - 1 ; i++) {
		ll x, y;
		cin >> x >> y;
        graph[x].push_back(y);
		graph[y].push_back(x);
	}

    dfs(1 , 1);

    ll node[n + 1] = {0};

    priority_queue < pair <ll , ll> > pq;

    for(ll i = 1 ; i <= n ; i++) {
        pq.emplace(make_pair(d[i] , i));
    }

    // for(ll i = 1 ; i <= n ; i++) {
    //     cout << d[i] << " ";
    // }
    // cout << endl;

    ll ans = 0;
    vector <pair<ll , ll> >  raw;
    while(m --) {
        pair <ll , ll> p = pq.top();
        pq.pop();
        ll val = p.first;
        ll curNode = p.second;
        // val --;
        ans += val;
        val --;
    }

    cout << ans << endl;

	return 0;
}
