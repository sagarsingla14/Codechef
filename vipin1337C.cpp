#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
#include <cstring>

#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
typedef pair<int, int> ii;

const long long MOD = 1e9 + 7;
vector<vector<int> > edge;

vector<int> nodes_depth(200005);
vector<long long> sub_size(200005);


void fill_depth(int node, int parent, int d) {

	nodes_depth[node] = d;
	long long x = 0;

	for(auto ch: edge[node]) {
		if(ch != parent) {
			fill_depth(ch, node, d + 1);
			x += sub_size[ch] + 1;
		}
	}
	sub_size[node] = x;
}

int main() {
	fast_io();

	int n, k; cin >> n >> k;

	edge.resize(n+1);
	for(int i = 0; i < n-1; ++i) {
		int u, v; cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	fill_depth(1, -1, 0);

	for(int i = 1 ; i <= n ; i++) {
		cout << sub_size[i] << " ";
	}
	cout << endl;

	vector<int> abc;
	for(int i = 1; i <= n; ++i) {
		abc.push_back(nodes_depth[i] - (sub_size[i]));
	}
	sort(abc.begin(), abc.end(), greater<int>());

	long long ans = 0;
	for(int i = 0; i < k; ++i) ans += abc[i];

	cout << ans << "\n";



}
