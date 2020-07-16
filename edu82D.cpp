#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll val , n;
        cin >> val >> n;

        priority_queue <ll , vector <ll> , greater<ll> > pq;
        for(ll i = 0 ; i < n ; i++) {
            ll x;
            cin >> x;
            pq.emplace(x);
        }

        ll curVal = val;
        ll i = 0;
        ll ans = 0;

        while(curVal > 0 && !pq.empty()) {
            if((val & (1ll << i)) == 0) {
                while(log2(pq.top()) <= i && !pq.empty()) {
                    ll cur = pq.top();
                    pq.pop();
                    if(pq.size() == 0) {
                        break;
                    }
                    ll nxt = pq.top();
                    pq.pop();
                    if(cur == nxt) {
                        pq.emplace(cur + nxt);
                    }
                    else{
                        pq.emplace(nxt);
                    }
                }
            }
            else {
                ll req = (1ll << i);
                if(pq.top() == req) {
                    pq.pop();
                    curVal -= req;
                    while(log2(pq.top()) <= i && !pq.empty()) {
                        ll cur = pq.top();
                        pq.pop();
                        if(pq.size() == 0) {
                            break;
                        }
                        ll nxt = pq.top();
                        pq.pop();
                        if(cur == nxt) {
                            pq.emplace(cur + nxt);
                        }
                        else {
                            pq.emplace(nxt);
                        }
                    }
                }
                else if(pq.top() > req) {
                    while(log2(pq.top()) != i) {
                        ll cur = pq.top();
                        pq.pop();
                        pq.emplace(cur / 2);
                        pq.emplace(cur / 2);
                        ans ++;
                    }
                    pq.pop();
                    curVal -= req;
                    while(log2(pq.top()) <= i && !pq.empty()) {
                        ll cur = pq.top();
                        pq.pop();
                        if(pq.size() == 0) {
                            break;
                        }
                        ll nxt = pq.top();
                        pq.pop();
                        if(cur == nxt) {
                            pq.emplace(cur + nxt);
                        }
                        else {
                            pq.emplace(nxt);
                        }
                    }
                }
            }
            i ++;
        }
        if(curVal > 0) {
            cout << -1 << endl;
        }
        else {
            cout << ans << endl;
        }
    }
    return 0;
}
