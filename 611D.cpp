#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , m;
priority_queue <pair <ll , ll> , vector <pair <ll , ll>> , greater<pair<ll, ll>>> pq;
ll ans = 0;
map <ll , ll> mp;
vector <ll> res;

int main() {
    fast_io

    cin >> n >> m;
    ll x;
    for(ll i = 0 ; i < n ; i++) {
        cin >> x;
        mp[x] = 1;
        pq.push({0ll , x});
    }

    if(n == 1 && m == 1) {
        cout << 1 << endl << x + 1 << endl;
        return 0;
    }


    ans = 0;
    for(ll i = 0 ; i < m ; i++) {
        pair <ll , ll> p = pq.top();
        ll dis = p.first;
        ll pos = p.second;
        if(mp[pos - 1] && mp[pos + 1]) {
            ans += dis;
            if(dis != 0) {
                res.push_back(pos);
            }
            i --;
            pq.pop();
        }
        else if(mp[pos + 1] == 0) {
            pq.push({dis + 1 , pos + 1});
            mp[pos + 1] = 1;
            if(mp[pos - 1]) {
                ans += dis;
                if(dis != 0) {
                    res.push_back(pos);
                }
                pq.pop();
            }
        }
        else if(mp[pos - 1] == 0) {
            pq.push({dis + 1 , pos - 1});
            mp[pos - 1] = 1;
            if(mp[pos + 1]) {
                ans += dis;
                if(dis != 0) {
                    res.push_back(pos);
                }
                pq.pop();
            }
        }
    }

    while(res.size() < m) {
        pair <ll , ll> p = pq.top();
        ll dis = p.first;
        ll pos = p.second;
        ans += dis;
        if(dis != 0) {
            res.push_back(pos);
        }
        pq.pop();
    }

    cout << ans << endl;
    for(auto i : res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
