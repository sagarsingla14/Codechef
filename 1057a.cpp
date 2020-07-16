#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n , found;
vector <ll> graph[200001];
vector <ll> ans;
ll visited[200001];
void dfs(ll start) {
    visited[start] = 1;
    if(start == n) {
        found = 1;
    }

    for(auto i : graph[start]) {
        if(!visited[i] && !found) {
            dfs(i);
        }
    }
    if(found) {
        ans.push_back(start);
    }
}
int main() {
    cin >> n;
    memset(visited , 0 , sizeof(visited));

    for(ll i = 2 ; i <= n ; i ++) {
        ll u;
        cin >> u;
        graph[u].push_back(i);
        graph[i].push_back(u);
    }

    dfs(1);

    reverse(ans.begin() , ans.end());
    for(auto i : ans) {
        cout << i << " ";
    }
    return 0;

}
