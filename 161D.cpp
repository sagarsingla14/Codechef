#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll n , m , k;
vector <ll> graph[100001];
ll visited[100001] = {0};
ll cnt = 0 , ok = 0 , stop = 0;
ll root = 1;
vector <ll> ans;

void dfs(ll start) {
    cnt ++;
    visited[start] = cnt;
    for(auto i : graph[start]) {
        if(!visited[i] && !ok) {
            dfs(i);
            if(ok && ans[0] != i && !stop) {
                ans.push_back(i);
            }
            if(ans[0] == i) {
                stop = 1;
            }
        }
        else{
            if(abs(visited[i] - visited[start]) >= k && !ok) {
                ans.push_back(i);
                ok = 1;
                break;
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for(ll i = 0 ; i < m ; i++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    cout << ans.size() << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
