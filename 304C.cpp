#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n;
    cin >> n;
    queue <ll> a , b;

    ll x;
    cin >> x;
    for(ll i = 0 ; i < x ; i++) {
        ll val;
        cin >> val;
        a.emplace(val);
    }

    cin >> x;
    for(ll i = 0 ; i < x ; i++) {
        ll val;
        cin >> val;
        b.emplace(val);
    }

    ll turns = 0;
    ll at , bt;
    ll flag = 0;
    while(!a.empty() && !b.empty()) {
        at = a.front();
        bt = b.front();
        a.pop();
        b.pop();
        if(at == bt) {
            flag = 1;
            break;
        }
        if(at > bt) {
            a.emplace(bt);
            a.emplace(at);
        }
        else {
            b.emplace(at);
            b.emplace(bt);
        }
        turns ++;
        if(turns >= 1e5) {
            flag = 1;
            break;
        }
    }

    if(flag) {
        cout << -1 << endl;
    }
    else{
        if(a.size() == 0) {
            cout << turns << " " << 2 << endl;
        }
        else{
            cout << turns << " " << 1 << endl;
        }
    }
    return 0;
}
