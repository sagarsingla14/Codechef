#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll fx[100001];
ll impos;
ll n;

void checkimpos() {
    for(ll i = 1 ; i <= n ; i++) {
        if(fx[i] != fx[fx[i]]) {
            impos = 1;
            break;
        }
    }
}

int main() {
    cin >> n;
    set <ll> s;
    for(ll i = 1 ; i <= n ; i++) {
        cin >> fx[i];
        s.insert(fx[i]);
    }
    ll m = s.size();
    ll val = 0;
    impos = 0;
    checkimpos();
    if(impos) {
        cout << -1 << endl;
    }
    else {
        ll gx[n + 1] = {0};
        ll hx[m + 1] = {0};
        for(ll i = 1 ; i <= n ; i++) {
            if(i >= m) {
                gx[i] = m;
            }
            else {
                gx[i] = i;
            }
        }
        for(ll i = 1 ; i <= m ; i++) {
            hx[i] = fx[gx[i]];
        }


        cout << m << endl;
        for(ll i = 1 ; i <= n ; i++) {
            cout << gx[i] << " ";
        }
        cout << endl;
        for(ll i = 1 ; i <= m ; i++) {
            cout << hx[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
