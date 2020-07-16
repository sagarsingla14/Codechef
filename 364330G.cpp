#include <bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
vector <ll> v;
vector <ll> graph[10000];
ll loc[6][10001];
ll visited[10001];
ll nodeans[10001];
ll ans;
ll n , k;
ll arr[6][10001];

// for(ll i = 0 ; i <= n; i++) {
//     cout << i << " i -> " ;
//     for(ll j = 0 ; j < graph[i].size() ; j++) {
//         cout << graph[i][j] << " ";
//     }
//     cout << endl;
// }


ll dfs(ll start) {
    visited[start] = 1;
    if(graph[start].size() == 0) {
        return 1;
    }
    else {
        ll cur = 0;
        for(ll i = 0 ; i < graph[start].size() ; i++) {
            if(!visited[graph[start][i]]) {
                cur = max(cur , dfs(graph[start][i]) + 1);
                return cur;
            }
        }
        return cur;
    }

    // for(ll i = 0; i < graph[start].size(); i++) {
    //     ll cur = graph[start][i];
    //     if(!visited[cur]) {
    //         dfs(cur);
    //     }
    //     nodeans[start] = max(nodeans[start], nodeans[cur] + 1);
    // }
    // if(nodeans[start] <= 1) {
    //     nodeans[start] = 1;
    // }
    // ans = max(ans, nodeans[start]);
    // return ;
}


int main() {
    cin >> n >> k;
    memset(visited , 0 , sizeof(visited));
    memset(nodeans , 0 , sizeof(nodeans));
    ans = 0;

    for(ll i = 0 ; i < k ; i ++) {
        for(ll j = 1 ; j <= n ; j++) {
            cin >> arr[i][j];
        }
    }
    for(ll i = 0 ; i < k ; i++) {
        for(ll j = 1 ; j <= n ; j ++) {
            loc[i][arr[i][j]] = j;
        }
    }

    for(ll i = 1 ; i <= n ; i++) {
        for(ll j = 1 ; j <= n; j ++) {
            ll temp = 1;
            if(i != j) {
                for(ll z = 0; z < k ; z ++) {
                    if(loc[z][i] >= loc[z][j]) {
                        temp = 0;
                        break;
                    }
                }
                if(temp) {
                    graph[i].push_back(j);
                }
            }
        }
    }

    // printGraph();
    ll ans = 0;
    for(ll i = 1 ; i <= n ; i ++) {
        if(!visited[i]) {
            ans = max(ans , dfs(i));
        }
    }

    cout << ans << endl;
    return 0;
}
