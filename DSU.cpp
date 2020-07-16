#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll parent[100001];
ll rnk[100001];

void make_Set(ll n) {
    for(ll i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

ll find(ll u) {
    if(parent[u] == u) {
        return u;
    }
    else{
        ll Representative = find(parent[u]);
        parent[u] = Representative;
        return parent[u];
    }
}

void un(ll u , ll v) {
    ll urep = find(u);
    ll vrep = find(v);

    if(urep == vrep) {
        return ;
    }
    else{
        if(rnk[urep] > rnk[vrep]) {
            parent[vrep] = urep;
        }
        else if(rnk[urep] < rnk[vrep]) {
            parent[urep] = vrep;
        }
        else {
            parent[vrep] = urep;
            rnk[urep] ++;
        }
    }
}

int main() {
    ll n;
    cin >> n;
    memset(parent , 0 , sizeof(parent));
    memset(rnk , 0 , sizeof(rnk));

    make_Set(n);

    un(1 , 3);
    un(2 , 5);
    un(4 , 3);
    un(1 , 2);

    for(ll i = 1 ; i <= n ; i++) {
        cout << " i- > " << find(i) << endl;
    }
    return 0;
}
