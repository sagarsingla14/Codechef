#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector <ll> graph[100001];
ll count[100001];
ll visited[100001];

map <ll , ll> mp;
vector<ll> ans;

void dfs(ll x , ll p) {
	visited[x] = 1;
	for(auto i : graph[x]) {
		if(!visited[i] && i != p) {
			dfs(i , x);
			count[x] += count[i];
		}
	}
	if(mp[x]) {
		count[x] ++;
	}
}

int main() {
	ll n;
	cin >> n;
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
	for(ll i = 1 ;  i <= n ; i++) {
		if(dp[i]==1) ans.push_back(i);
	}
	cout<<ans.size()<<endl;
	for(int i=0; i<ans.size(); i++) {
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
