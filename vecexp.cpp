#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector <ll> ans;
ll parent[100001];
ll rnk[100001];

void make_Set(ll n) {
    for(ll i = 0 ; i <= n ; i ++) {
        parent[i] = i;
        rnk[i] = 0;
    }
}

ll find(ll x) {
    if(parent[x] == x) {
        return x;
    }
    else{
        ll rep = find(parent[x]);
        return rep;
    }
}

void Union(ll x , ll y , ll index) {
    ll xrep = find(x);
    ll yrep = find(y);
    if(xrep == yrep) {
        return ;
    }
    else{
        ans.push_back(index);
        if(rnk[xrep] > rnk[yrep]) {
            parent[yrep] = xrep;
        }
        else if(rnk[xrep] < rnk[yrep]) {
            parent[xrep] = yrep;
        }
        else{
            parent[yrep] = xrep;
            rnk[xrep] ++;
        }
    }
}

struct Node {
    ll u , v , w;
};

bool comp(const Node* a , const Node* b) {
    return a -> w < b -> w;
}

int main() {
    ll n , e;
    cin >> n >> e;
    vector <Node*> v;
    for(ll i = 0 ; i < e ; i++) {
        ll a , b , weight;
        cin >> a >> b >> weight;
        Node *temp = new Node();
        temp -> u = a;
        temp -> v = b;
        temp -> w = weight;
        v.push_back(temp);
    }
    sort(v.begin() , v.end() , comp);

    make_Set(n);

    for(ll i = 0 ; i < e ; i++) {
        Union(v[i] -> u , v[i] -> v , i);
    }
    for(ll j = 0 ; j < ans.size() ; j++) {
        ll i = ans[j];
        cout << v[i] -> u << " " << v[i] -> v << " " << v[i] -> w << endl;
    }
}
