#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll arr[101][101];
vector <ll> graph[101];
ll dfsnum[101];
ll dfslow[101];
ll parent[101];
ll ap[101];
ll n;
ll dfsNumberCounter = 0 , dfsroot = 0 , rootchildren = 0;

void articulation(int u) {
    dfslow[u] = dfsNumberCounter;
    dfsnum[u] = dfsNumberCounter;

    dfsNumberCounter ++;

    for(auto i : graph[u]) {
        if(dfsnum[i] == -1) {
            parent[i] = u;
            if(u == dfsroot) {
                rootchildren ++;
            }
            articulation(i);
            
            if(dfslow[i] >= dfsnum[u]) {
                ap[u] = 1;
            }
            dfslow[u] = min(dfslow[u] , dfslow[i]);
        }
        else if(i != parent[u]) {
            dfslow[u] = min(dfslow[u] , dfsnum[i]);
        }
    }
}

int main() {
    cin >> n;
    memset(arr , 0 , sizeof(arr));
    memset(ap , 0 , sizeof(ap));

    dfsNumberCounter = 0;

    for(ll i = 1 ; i <= n ; i++) {
        for(ll j = 1 ; j <= n;  j++) {
            cin >> arr[i][j];
            if(arr[i][j]) {
                graph[i].push_back(j);
            }
        }
    }

    for(ll i = 0 ; i <= 100 ; i++) {
        dfsnum[i] = -1;
        dfslow[i] = 0;
        parent[i] = 0;
    }

    for(ll i = 1 ; i <= n ; i++) {
        if(dfsnum[i] == -1) {
            dfsroot = i;
            rootchildren = 0;
            articulation(i);
            ap[dfsroot] = (rootchildren > 1);
        }
    }

    ll ans = 0;
    for(ll i = 1 ; i <= n ; i++) {
        if(ap[i]) {
            ans ++;
        }
    }
    cout << ans << endl;

    return 0;
}
