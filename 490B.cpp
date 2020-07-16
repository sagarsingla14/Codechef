#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector <ll> fwd;
vector <ll> bwd;

int main() {
    ll n;
    cin >> n;
    unordered_map <ll , ll> f;
    unordered_map <ll , ll> present;

    for(ll i = 0 ; i < n ; i++) {
        ll u , v;
        cin >> u >> v;
        f[u] = v;
        present[v] = 1;
    }

    ll cur = 0;
    for(auto itr = f.begin(); itr != f.end() ;itr++) {
        if(present[itr -> first] == 0) {
            cur = itr -> first;
            break;
        }
    }

    fwd.push_back(cur);
    while(f[cur]) {
        cur = f[cur];
        fwd.push_back(cur);
    }

    cur = f[0];
    bwd.push_back(cur);
    while(f[cur]) {
        cur = f[cur];
        bwd.push_back(cur);
    }

    for(ll i = 0 ; i < min(bwd.size() , fwd.size()) ; i++) {
        cout << fwd[i] << " " << bwd[i] << " ";
    }

    if(bwd.size() > fwd.size()) {
        cout << bwd[bwd.size() - 1] << " ";
    }
    else if(bwd.size() < fwd.size()){
        cout << fwd[fwd.size() - 1] << " ";
    }
    cout << endl;
    return 0;
}
