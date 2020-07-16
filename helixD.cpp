#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

struct Node {
    ll l , r , c;
};


ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }

    return res;
}

bool sortbyX(Node* a , Node *b) {
    return a -> l < b -> l;
}

int main() {
    ll n;
    cin >> n;

    ll lll , rr , cc;
    vector <Node*> v;
    for(ll i = 0 ; i < n ; i++) {
        cin >> lll >> rr >> cc;
        Node* node = new Node();
        node -> l = lll;
        node -> r = rr;
        node -> c = cc;
        v.push_back(node);
    }

    sort(v.begin() , v.end() , sortbyX);

    ll ans = 9e18;
    for(ll i = 0 ; i < n ; i++) {
        for(ll j = i ; j < n ; j ++) {
            if(v[j] -> l > v[i] -> r) {
                ll cur = v[i] -> c * v[j] -> c;
                ans = min(ans , cur);
            }
        }
    }

    ll temp = 9e18;
    if(ans == temp) {
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }

    return 0;
}
