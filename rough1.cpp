#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector <ll> graph[100001];
ll dp[100001];
ll visited[100001];

map <ll , ll> mp;
vector<ll> ans;

void dfs(ll x , ll p) {
	visited[x] = 1;
	for(auto i : graph[x]) {
		if(!visited[i] && i != p) {
			dfs(i , x);
			dp[x] += dp[i];
		}
	}
	if(mp[x]) {
		dp[x] ++;
	}
}

int main() {
	ll n;
	cin >> n;

	memset(visited , 0 , sizeof(visited));
	memset(dp , 0 , sizeof(dp));
	for(ll i = 0 ; i < n - 1 ; i++) {
		ll x , y , t;
		cin >> x >> y >> t;
		graph[x].push_back(y);
		graph[y].push_back(x);
		if(t == 2) {
			mp[x] = 1;
			mp[y] = 1;
		}
	}

	dfs(1 , 1);
	ll j = 0;
	for(auto i : dp) {
		if(i == 1) {
			ans.push_back(j);
		}
		j ++;
	}

	cout << ans.size() << endl;
	for(auto i : ans) {
		cout << i << " ";
	}
	cout<<endl;
	return 0;
}
