#include <bits/stdc++.h>
#define ll long long int
#define train_choot_jayegi ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll n , m;
vector <ll> graph[50001];
ll visited[50001];
ll sum[50001];
map <pair <ll , ll> , ll> mp;

void bfs(ll start) {

    queue <ll> q;
    q.emplace(start);
    while(!q.empty()) {
        ll val = q.front();
        visited[val] = 1;
        q.pop();
        for(auto i : graph[val]) {
            if(!visited[i]) {
                q.emplace(i);
                ll weight = mp[{val , i}];
                ll diff = (weight - sum[val]);
                if(diff <= 0) {
                    diff = 0;
                }
                sum[i] = min(sum[i] , sum[val] + diff);
            }
        }
    }
}

void initializeSum() {
    for(ll i = 1 ; i <= n ; i++) {
        if(i == 1) {
            sum[i] = 0;
        }
        else{
            sum[i] = 1e17;
        }
    }
}

using namespace std;
int main() {
    train_choot_jayegi
    cin >> n >> m;

    memset(visited , 0 , sizeof(visited));
    initializeSum();
    for(ll i = 0 ; i < m ; i++) {
        ll u , v , w;
        cin >> u >> v >> w;
        graph[u].push_back(v);
        graph[v].push_back(u);
        mp[{u , v}] = w;
        mp[{v , u}] = w;
    }

    bfs(1);

    cout << sum[n] << endl;
    return 0;
}
