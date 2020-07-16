#include <bits/stdc++.h>
#define ll long long int
#define train_choot_jayegi_mere_bina ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector <ll> graph[100001];
ll visited[100001];
ll ok = 1;
ll n , m;

void dfs(ll start) {
    visited[start] = 1;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    memset(visited , 0 , sizeof(visited));
    cin >> n >> m;
    for(ll i = 0 ; i < m ; i++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if(m != n - 1) {
        cout << "no" << endl;
    }
    else{
        ok = 1;
        dfs(1);
        for(ll i = 1 ; i <= n ; i++) {
            if(!visited[i]) {
                ok = 0;
            }
        }
        if(!ok) {
            cout << "no" << endl;
        }
        else{
            cout << "yes" << endl;
        }
    }
    return 0;
}
