#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


string graph[5001];
ll visited[5001] = {0};
vector <ll> ans;
ll ok = 0;
ll n;

void dfs(ll root , ll parent) {
    visited[root] = 1;
    for(ll i = 1 ; i <= n ; i++) {
        if(graph[root][i] == '1') {
            if(graph[i][parent] == '1' && !ok) {
                ans.push_back(parent);
                ans.push_back(root);
                ans.push_back(i);
                ok = 1;
            }
            if(!visited[i] && !ok) {
                dfs(i , root);
            }
        }
    }
}

int main() {
    fast_io
    cin >> n;
    for(ll i = 1 ; i <= n ; i++) {
        graph[i] = "0";
        string str;
        cin >> str;
        graph[i] += str;
    }

    for(ll i = 1 ; i <= n ; i++) {
        dfs(i , 0);
    }

    if(ok) {
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }
    return 0;
}
