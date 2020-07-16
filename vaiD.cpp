#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;

    vector <ll> edges[100001];
    for(ll i = 1; i <= m; i++){
        ll u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }


    priority_queue<ll, vector<ll>, greater<ll> > pq;
    bool visited[100001];
    memset(visited , false , sizeof(visited));
    visited[1] = true;
    pq.push(1);

    while(!pq.empty()){
        ll curr = pq.top();
        pq.pop();
        cout << curr << " ";
        for(auto it : edges[curr]){
            if(!visited[it]){
                pq.push(it);
                visited[it] = true;
            }
        }
    }
	return 0;
}
