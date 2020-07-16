#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll degree[n + 1] = {0};
    ll power[n + 1] = {0};

    for(ll i = 0 ; i < (n * (n - 1)) / 2  - 1 ; i++) {
        ll x , y;
        cin >> x >> y;
        degree[x] ++;
        degree[y] ++;
        power[x] ++;
    }

    vector <ll> v;
    for(ll i = 1 ; i <= n ; i++) {
        if(degree[i] == n - 2) {
            v.push_back(i);
        }
    }

    if(power[v[0]] > power[v[1]]) {
        cout << v[0] << " " << v[1] << endl;
    }
    else{
        cout << v[1] << " " << v[0] << endl;
    }

    return 0;
}
