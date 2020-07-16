#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
ll n;
unordered_map <ll , ll> mp;
priority_queue <ll> pq;

int main() {
    fast_io
    cin >> n;
    ll arr[n * n] = {0};

    for(ll i = 0 ; i < n * n ; i++) {
        cin >> arr[i];
        mp[arr[i]] ++;
        pq.emplace(arr[i]);
    }

    ll mx = pq.top();
    pq.pop();
    mp[mx] --;
    vector <ll> v;
    v.push_back(mx);

    while(v.size() < n && !pq.empty()) {
        ll curMax = pq.top();
        pq.pop();
        if(mp[curMax]) {
            mp[curMax] --;
            for(ll i = 0 ; i < v.size() ; i++) {
                ll g = __gcd(v[i] , curMax);
                mp[g] --;
                mp[g] --;
            }
            v.push_back(curMax);
        }
    }
    
    for(auto i : v) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
