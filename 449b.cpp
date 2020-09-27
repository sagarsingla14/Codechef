#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<ii> vii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, m, k, a, b, c;
	cin >> n >> m >> k;
	vi trains(n + 1, 0);
	vi dist(n + 1, INT_MAX);
	vector<vii > v(n + 1, vii(0, {0, 0}));
	priority_queue<pair<ll, ii> > pq;
	while(m--) { cin >> a >> b >> c; v[a].pb({b, c}); v[b].pb({a, c}); }
	while(k--) { cin >> a >> b; pq.push({-b, {a, 1}}); }
	pq.push({0, {1, 0}});
	dist[1] = 0;
	ll ans = 0;
	while(!pq.empty())
	{
		ll wt = -pq.top().fi;
		a = pq.top().se.fi;
		b = pq.top().se.se;
		cout << "=> " << a << " " << b << " " << wt << endl;

		pq.pop();
		if(b)
		{
			cout << "In" << endl;
			if(dist[a] <= wt)
			{
				ans++;
				continue;
			}
			else dist[a] = wt;
		}
		else if(dist[a] < wt) continue;
		for(ll i = 0; i < (ll)v[a].size(); i++)
		{
			b = v[a][i].fi;
			wt = v[a][i].se;
			if(dist[b] > dist[a] + wt)
			{
				dist[b] = dist[a] + wt;
				pq.push({-dist[b], {b, 0}});
			}
		}
	}
	cout << ans;
}
