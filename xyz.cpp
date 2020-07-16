#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n, m;
vector <ll> graph[100001];
ll visited[100001];
ll d[100001];
ll parent[100001];
ll ans = 0;
ll child[100001];
vector <pair <ll , ll> > l;

void dfs(ll start , ll level , ll p) {
    visited[start] = 1;
    parent[start] = p;
    d[start] = level;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i , d[start] + 1 , start);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(visited , 0 , sizeof(visited));
    memset(d , 0 , sizeof(d));
    memset(parent , 0 , sizeof(parent));

    cin >> n >> m;
	for(ll i = 0 ; i < n - 1 ; i++) {
		ll x, y;
		cin >> x >> y;
        graph[x].push_back(y);
		graph[y].push_back(x);
	}

    dfs(1 , 1 , 0);

    ll node[n + 1] = {0};

    priority_queue < pair <ll , ll> > pq;

    for(ll i = 1 ; i <= n ; i++) {
        pq.emplace(make_pair(d[i] , i));
        // l.push_back(make_pair(i , d[i]));
    }

    // sort(l.begin() , l.end() , sortBySec);

    for(ll i = 1 ; i <= n ; i++) {
        // cout << d[i] << " ";
    }
    cout << endl;


    while(m --) {
        pair <ll , ll> p = pq.top();
        pq.pop();
        ll val = p.first;
        ll curNode = p.second;
        // cout << curNode << endl;
        if(graph[curNode].size() == 1) {
            child[curNode] += 1;
        }
        else{
            for(auto i : graph[curNode]) {
                if(i != parent[curNode]) {
                    if(child[i]) {
                        child[curNode] = 1;
                    }
                }
            }
        }
        // ans += val;
    }
    ll one = 0 , zero = 0;
    ans = 0;
    for(ll i = 1 ; i <= n; i++) {
        // cout << child[i] << " ";
        if(child[i]) {
            one ++;
        }
        else{
            zero ++;
        }
    }


    cout << endl;

    // final();

    cout << ans << endl;

	return 0;
}
