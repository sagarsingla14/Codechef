#include <iostream>
#include <map>
using namespace std;
#define ll long long int

map <ll , ll> mp;
ll cnt = 0 , ans = 0;

void fillMap(ll x) {
    cnt = 0;
    mp[x] = 0;
    for(ll i = 2 ; i * i <= x ; i++) {
        while(x % i == 0) {
            x /= i;
            mp[x] = ++cnt;
        }
    }
    if(x) {
        mp[1] = ++cnt;
    }
}

void calcAns(ll x) {
    ll found = 0;
    cnt = 0;
    if(mp.find(x) != mp.end()) {
        found = 1;
        ans = cnt + mp[x];
    }
    if(!found) {
        for(ll i = 2 ; i * i <= x ; i++) {
            while(x % i == 0 && !found) {
                x /= i;
                ++cnt;
                if(mp.find(x) != mp.end()) {
                    found = 1;
                    ans = cnt + mp[x];
                    break;
                }
            }
            if(found) {
                break;
            }
        }
        if(x && !found) {
            ++cnt;
            ans = mp[1] + cnt;
        }
    }
}

void solve() {
    ll x , y;
    cin >> x >> y;

    ans = 0 , cnt = 0;
    mp.clear();

    ll mx = max(x , y);
    ll mn = min(x , y);

    if(x == y) {
        cout << 0;
    }
    else {
        fillMap(mx);
        calcAns(mn);
        cout << ans;
    }
}

int main() {
    solve();
    return 0;
}
