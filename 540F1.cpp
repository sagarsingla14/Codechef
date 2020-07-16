#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector <ll> graph[300001];
ll visited[300001];
ll arr[300001];
ll red[300001];
ll blue[300001];
ll b ,r, n;
ll ans;

void dfs(ll start) {
    visited[start] = 1;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i);
            blue[start] += blue[i];
            red[start] += red[i];
        }
    }
    if(arr[start] == 1) {
        blue[start] ++;
    }
    if(arr[start] == 2) {
        red[start] ++;
    }

    if(blue[start] == 0 && red[start] != 0) {
        if(r - red[start] == 0) {
            ans ++;
        }
    }
    else if(blue[start] != 0 && red[start] == 0){
        if(b - blue[start] == 0) {
            ans ++;
        }
    }
}


int main() {
    memset(arr , 0 , sizeof(arr));
    memset(red , 0 , sizeof(red));
    memset(blue , 0 , sizeof(blue));
    memset(visited , 0 , sizeof(visited));

    cin >> n;
    b = 0 , r = 0 , ans = 0;
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
        if(arr[i] == 1) {
            b ++;
        }
        if(arr[i] == 2) {
            r ++;
        }
    }

    for(ll i = 0 ; i < n - 1; i++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    cout << ans << endl;
    return 0;
}
