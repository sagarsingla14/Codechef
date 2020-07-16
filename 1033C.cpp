#include <bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
vector <ll> graph[100001];
ll arr[100001];

void printGraph() {
    for(ll i = 0 ; i <= 20 ; i++) {
        cout << i << " i- >  ";
        for(ll j = 0 ; j < graph[i].size() ; j ++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}


ll isEdge(ll val , ll i , ll j) {
    if(abs(i - j) % val == 0 && val < arr[j]) {
        return 1;
    }
    return 0;
}

ll dfs(ll val , ll turn) {
    if(graph[val].size() == 0) {
        if(turn % 2) {
            return 1;
        }
        else{
            return 0;
        }
    }

    ll check = 0;
    for(ll i = 0 ; i < graph[val].size() ; i++) {
        if(dfs(graph[val][i] , turn + 1)) {
            check = 1;
            return 1;
        }
    }
    return check;
}

int main() {
    ll n;
    cin >> n;
    memset(arr , 0 , sizeof(arr));
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    for(ll i = 0 ; i < n ; i++) {
        ll val = arr[i];
        for(ll j = i + val ; j < n ; j += val) {
            if(isEdge(val , i , j)) {
                graph[val].push_back(arr[j]);
            }
        }
        for(ll j = i - val ; j >= 0 ; j -= val) {
            if(isEdge(val , i , j)) {
                graph[val].push_back(arr[j]);
            }
        }
    }

    printGraph();
    for(ll i = 0 ; i < n ; i++) {
        if(dfs(arr[i] , 0)) {
            cout << "A";
        }
        else{
            cout << "B";
        }
    }
    return 0;

}
