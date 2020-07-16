#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1e18

ll n , ans , root , k;
ll visited[300001];
ll depth[300001];
vector <ll> graph[300001];
ll size[300001];

void dfs(ll start , ll parent) {
    visited[start] = 1;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            depth[i] += (depth[start] + 1);
            dfs(i , start);
        }
    }
}

void subSize(ll start) {
    visited[start] = 1;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            subSize(i);
            size[start] += (size[i] + 1);
        }
    }
}

int main() {
    cin >> n >> k;

    memset(visited , 0 , sizeof(visited));
    memset(depth , 0 , sizeof(depth));
    memset(size , 0 , sizeof(size));

    for(ll i = 0 ; i < n - 1 ; i++) {
        ll x , y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    depth[1] = 0;
    dfs(1 , 0);

    memset(visited , 0 , sizeof(visited));
    subSize(1);

    for(ll i = 1 ; i <= n ;i ++) {
        cout << size[i] << " ";
    }
    cout << endl;

    priority_queue <ll> pq;
	for(ll i = 1 ; i <= n ; i++) {
		pq.emplace(depth[i] - size[i]);
	}

    ans = 0;
    for(ll i = 0 ; i < k ; i++) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;

    return 0;
}
