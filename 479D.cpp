#include <bits/stdc++.h>
#define ll long long int
using namespace std;
map <ll , ll> mp;
map <ll , ll> pushed;
vector <ll> graph[1001];
ll n;
ll arr[1001];
ll visited[1001];
ll start;
void findStart() {
    for(ll i = 1 ; i <= n ; i++) {
        if(!pushed[i]) {
            start = i;
            break;
        }
    }
}

void dfs(ll s) {
    visited[s] = 1;
    for(auto i : graph[s]) {
        if(!visited[i]) {
            cout << arr[i] << " ";
            dfs(i);
        }
    }
}

int main() {
    cin >> n;

    memset(arr , 0 , sizeof(arr));
    memset(visited , 0 , sizeof(visited));
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
        mp[arr[i]] = i;
    }

    for(ll i = 1 ; i <= n ; i++) {
        ll div = arr[i] / 3;
        ll mul = arr[i] * 2;
        if(mp[mul]) {
            graph[i].push_back(mp[mul]);
            pushed[mp[mul]] ++;
        }
        if(mp[div] && (arr[i] % 3 == 0)) {
            pushed[mp[div]] ++;
            graph[i].push_back(mp[div]);
        }
    }

    start = 0;
    findStart();
    cout << arr[start] << " ";
    dfs(start);
    cout << endl;
    return 0;
}
