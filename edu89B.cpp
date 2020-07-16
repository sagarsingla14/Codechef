#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector <ll> graph[1000];

vector <vector <ll> > allPaths;

void printpath(vector <ll>& path) {
	ll size = path.size();
    vector <ll> cur;

	for(ll i = 0 ; i < size ; i++)
		cur.push_back(path[i]);

    for(auto i : cur) {
        cout << i << " ";
    }
    cout << endl;

    allPaths.push_back(cur);
}

ll isNotVisited(ll x, vector<ll> & path) {
	ll size = path.size();
	for (ll i = 0; i < size; i++)
		if (path[i] == x)
			return 0;
	return 1;
}

void findpaths(ll src , ll dst, ll v) {
	queue< vector<ll> > q;
	vector <ll> path;
	path.push_back(src);
	q.push(path);
	while (!q.empty()) {
		path = q.front();
		q.pop();
		ll last = path[path.size() - 1];

		if (last == dst)
			printpath(path);

		for (ll i = 0; i < graph[last].size(); i++) {
			if (isNotVisited(graph[last][i], path)) {
				vector <ll> newpath(path);
				newpath.push_back(graph[last][i]);
				q.push(newpath);
			}
		}
	}
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , m;
        cin >> n >> m;

        map <pair <ll , ll> , ll> mp;
        map <ll , pair <ll , ll> > node;

        ll arr[n + 1][m + 1];
        for(ll i = 1 ; i <= n ; i++) {
            for(ll j = 1 ; j <= m ; j++) {
                cin >> arr[i][j];
            }
        }


        ll cnt = 0;
        for(ll i = 1 ; i <= n ; i++) {
            for(ll j = 1 ; j <= m ; j++) {
                cnt ++;
                mp[{i , j}] = cnt;
                node[cnt] = {i , j};
            }
        }

        for(auto i : mp) {
            cout << i.first.first << " "
        }

        for(ll i = 1 ; i < n ; i++) {
            for(ll j = 1 ; j < m ; j++) {
                graph[mp[{i , j}]].push_back(mp[{i + 1 , j}]);
                graph[mp[{i , j}]].push_back(mp[{i , j + 1}]);
            }
        }

        ll src = 1 , dst = n * m;
        ll v = n * m;
        findpaths(src , dst , v);
    }
	return 0;
}
