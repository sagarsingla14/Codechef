#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define INF 1000000000000000000
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , m , x , ans = 0;
vector <pair <ll , ll>> graph[100001];
priority_queue <pair <ll , pair <ll , ll>>> pq;

int main() {
	fast_io
	cin >> n >> m >> x;
	for(ll i = 0 ; i < m; i++) {
		ll u , v , w;
		cin >> u >> v >> w;
		graph[u].push_back({v , w});
		graph[v].push_back({u , w});
	}
	for(ll i = 0 ; i < x ; i ++) {
		ll u , w;
		cin >> u >> w;
		pq.push({-w , {-u , 1}});
	}

	ll dp[n + 1] = {0};
	for(ll i = 0 ; i <= n ; i++) {
		dp[i] = INF;
	}

	dp[1] = 0;
	pq.push({-dp[1] , {-1 , 0}});
	while(!pq.empty()) {
		pair <ll , pair <ll , ll>> p = pq.top();
		ll wt = -p.first;
		ll u = -p.second.first;
		ll t = p.second.second;
		pq.pop();
		if(t) {
			if(dp[u] <= wt) {
				ans ++;
			}
			else {
				dp[u] = wt;
			}
		}
		if(!visited[u]) {
			for(auto i : graph[u]) {
				wt = i.second;
				ll v = i.first;
				if(dp[v] > wt + dp[u]) {
					dp[v] = wt + dp[u];
					pq.push({-dp[v] , {-v , 0}});
				}
			}
		}
		visited[u] = 1;
	}
	cout << ans << endl;
	return 0;
}
