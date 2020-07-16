#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n , m , x , height , subheight;
ll visited[500001];
ll arr[500001];
ll value[500001];
ll degree[500001];

vector <ll> graph[500001];
ll ans;

void findHeight(ll start , ll h) {
    height = max(h , height);
    visited[start] = 1;

    for(auto i : graph[start]) {
        if(!visited[i]) {
            findHeight(i , h + 1);
        }
    }
}

void clearGraph() {
    for(ll i = 1 ; i <= x ; i++) {
        graph[i].clear();
    }
}

void cp() {
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
}


int main() {
    cp();

    memset(visited , 0 , sizeof(visited));
    memset(degree , 0 , sizeof(degree));

    ans = 0;
    cin >> n;
    for(ll i = 0 ; i < n ; i++) {
        cin >> x;
        memset(degree , 0 , sizeof(degree));
        for(ll i = 0 ; i < x - 1 ; i++) {
            ll u , v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u] ++;
            degree[v] ++;
        }

        // cout << "start height " << start << " ";
        height = 0 , subheight = 0;
        for(ll i = 1 ; i <= x ; i++) {
            subheight = 0;
            if(degree[i] == 1) {
                memset(visited , 0 , sizeof(visited));
                findHeight(i , 0);
                height = max(subheight , height);
            }
        }
        // cout << height << endl;
        ans += height;
        clearGraph();
    }

    cout << ans << endl;
    return 0;
}
