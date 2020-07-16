#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector <pair <ll , ll> > graph[250000];
ll visited[250000];
ll n;

vector <ll> result;

bool sortbysec(pair <ll , ll> p1 , pair <ll , ll> p2) {
    return (p1.second < p2.second);
}

void bfs(ll start) {
    result.push_back(start);
    visited[start] = 1;
    queue <ll> q;
    q.push(start);
    while(!q.empty()) {
        ll parent = q.front();
        q.pop();
        for(auto i : graph[parent]) {
            if(!visited[i.first]) {
                visited[i.first] = 1;
                q.push(i.first);
                result.push_back(i.first);
            }
        }
    }
}

void sortGraph() {
    for(ll i = 1 ; i <= n ; i++) {
        sort(graph[i].begin() , graph[i].end() , sortbysec);
    }
}

int main() {
    cin >> n;
    memset(visited , 0 , sizeof(visited));
    vector <pair <ll , ll> > tree;
    for(ll i = 0 ; i < n - 1 ; i++) {
        ll u , v;
        cin >> u >> v;
        tree.push_back(make_pair(u , v));
    }

    ll arr[n + 1] = {0};
    map <ll , ll> mp;
    for(ll i = 1 ; i <= n ; i++){
        cin >> arr[i];
        mp[arr[i]] = i;
    }

    for(ll i = 0 ; i < n - 1 ; i++) {
        graph[tree[i].first].push_back(make_pair(tree[i].second , mp[tree[i].second]));
        graph[tree[i].second].push_back(make_pair(tree[i].first , mp[tree[i].first]));
    }

    sortGraph();

    if(arr[1] != 1) {
        cout << "NO" << endl;
        return 0;
    }

    bfs(1);
    ll ans = 1;
    for(ll i = 1 ; i < n ; i++) {
        if(arr[i] != result[i - 1]) {
            ans = 0;
            break;
        }
    }

    // for(auto i : result) {
    //     cout << i << " ";
    // }
    // cout << endl;

    if(ans) {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
