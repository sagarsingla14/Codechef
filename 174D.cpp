#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll arr[200001] = {0};
vector <ll> graph[200001];
vector <ll> visited(200001 , 0);
ll sum = 0 , cycle = 0;

void dfs(ll start , ll parent) {
    visited[start] = 1;
    sum = arr[start];

    for(auto i : graph[start]) {
        if(i != parent) {
            continue;
        }
        else if(!visited[i]) {
            dfs(i , start);
        }
        else {
            cycle = 1;
            break;
        }
    }
}

int main() {
    ll n;
    cin >> n;
    vector <pair <ll , ll> > v;
    v.push_back({0 , 0});
    v.push_back({0 , 0});

    for(ll i = 2 ; i <= n ; i++) {
        cin >> arr[i];
        v.push_back({arr[i] , (i - arr[i])});
        if(i - arr[i] > 0 && i - arr[i] <= n) {
            graph[i].push_back(i - arr[i]);
        }
    }

    for(ll i = 1 ; i <= n ; i++) {
        visited.clear();
        sum = i;
        cycle = 0;
        visited[1] = 1;
        dfs(i + 1 , i + 1);

        if(cycle) {
            cout << -1 << endl;
        }
        else {
            cout << sum << endl;
        }
    }

    return 0;
}
