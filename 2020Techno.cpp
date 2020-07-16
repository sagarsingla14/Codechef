#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll pos = 0 , ans = 0;
ll n , p;
priority_queue <ll> pq;

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

ll countBits(ll x) {
    pq = priority_queue <ll>();
    ll bit = 0;
    ll cnt = 0;
    while(x) {
        if(x & 1) {
            cnt ++;
            pq.emplace(power(2ll , bit));
        }
        bit ++;
        x >>= 1;
    }
    return cnt;
}

ll canBrake(ll setBits) {
    while(pq.size() < setBits) {
        if(pq.top() == 1) {
            break;
        }
        else{
            ll val = pq.top();
            pq.pop();
            pq.emplace(val / 2);

            pq.emplace(val / 2);
        }
    }
    if(pq.size() == setBits) {
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
    cin >> n >> p;

    for(ll i = 1 ; i <= 31 ; i++) {
        if(n - (i * p) > 0) {
            ll setBits = countBits(n - (i * p));
            if(setBits <= i) {
                ll ok = canBrake(i);
                if(ok) {
                    pos = 1;
                    ans = i;
                    break;
                }
            }
        }
        else{
            break;
        }
    }

    if(!pos) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }
    return 0;
}
