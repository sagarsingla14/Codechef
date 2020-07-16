#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll t;
    cin >> t;
    ll c = 1;
    while(t--) {
        ll n , k;
        cin >> n >> k;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        priority_queue <ll> pq;
        for(ll i = 1 ;  i < n ; i++) {
            ll d = abs(arr[i] - arr[i - 1]);
            pq.push(d);
        }
        while(k) {
            ll val = pq.top();
            pq.pop();
            ll a = 0 , b = 0;
            a = val / 2;
            b = val / 2;
            if(val % 2) {
                a ++;
            }
            pq.push(a);
            pq.push(b);
            if(pq.top() == 1) {
                break;
            }
            k --;
        }
        cout << "Case #" << c << ": " << pq.top() << endl;
        c ++;
    }
    return 0;
}
