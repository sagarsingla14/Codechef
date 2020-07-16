#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool sortBySec(pair <ll , ll> a , pair <ll , ll> b) {
	return a.second < b.second;
}

int main() {
	ll n;
	cin >> n;
	vector <pair <ll , ll> > v;
	for(ll i = 0 ; i < n; i++) {
		ll x , y;
		cin >> x >> y;
		v.push_back(make_pair(x , y));
	}
	sort(v.begin() , v.end() , sortBySec);
	ll ans = 1;
	ll endtime = v[0].second;
	for(ll i = 1 ; i < n ; i++) {
		if(v[i].first > endtime) {
			ans ++;
			endtime = v[i].second;
		}
	}

	cout << ans << endl;
	return 0;
}
