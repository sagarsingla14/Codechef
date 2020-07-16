#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fast_io
    ll n , m;
    cin >> n >> m;
    priority_queue <ll , vector <ll> , greater <ll> > a;
    priority_queue <ll> b;

    ll x;
    for(ll i = 0 ; i < n ; i++) {
        cin >> x;
        a.emplace(x);
    }
    for(ll i = 0 ; i < m ; i++) {
        cin >> x;
        b.emplace(x);
    }

    ll ans = 0;
    while(!a.empty() && !b.empty() && a.top() < b.top()) {
        ll curA = a.top();
        ll curB = b.top();

        ans += (curB - curA);

        a.pop();
        b.pop();
    }
    cout << ans << endl;

    return 0;
}
