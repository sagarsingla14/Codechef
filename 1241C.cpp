#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        priority_queue <ll> pq;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            pq.push(arr[i]);
        }

        ll sze = pq.size();

        ll x,a,y,b,k;
        cin >> x >> a >> y >> b >> k;
        ll lcm = a * b;

        ll val_lcm = n / lcm;
        ll count = 0;
        ll d = x + y;
        ll flag = 0;
        ll temp = 0;

        for(ll i = 0 ; i < val_lcm ; i++) {
            ll price = pq.top();
            price /= 100;
            price *= d;
            pq.pop();
            k -= price;
            count++;
            if(k <= 0) {
                temp = 1;
                break;
            }
            if(pq.size() == 0) {
                flag = 1;
                break;
            }
        }

        if(temp) {
            cout << count << endl;
            continue;
        }

        if(flag) {
            if(k > 0) {
                cout << -1 <<endl;
                continue;
            }
            else{
                cout << count << endl;
                continue;
            }
        }

        ll val_max = max(x , y);
        ll val_min = min(x , y);
        ll pmax, pmin;

        if(val_max == x) {
            pmax = a;
            pmin = b;
        }
        else{
            pmax = b;
            pmin = a;
        }

        d = val_max;
        val_max = n / pmax;
        val_max -= val_lcm;

        for(ll i = 0 ; i < val_max ; i++) {
            ll price = pq.top();
            price /= 100;
            price *= d;
            pq.pop();
            k -= price;
            count++;
            if(k <= 0) {
                temp = 1;
                break;
            }
            if(pq.size() == 0) {
                flag = 1;
                break;
            }
        }

        if(temp) {
            cout << count << endl;
            continue;
        }

        if(flag) {
            if(k > 0) {
                cout << -1 <<endl;
                continue;
            }
            else{
                cout << count << endl;
                continue;
            }
        }

        d = val_min;
        val_min = n / pmin;
        val_min -= val_lcm;

        for(ll i = 0 ; i < val_min ; i++) {
            ll price = pq.top();
            price /= 100;
            price *= d;
            pq.pop();
            k -= price;
            count++;
            if(k <= 0) {
                temp = 1;
                break;
            }
            if(pq.size() == 0) {
                flag = 1;
                break;
            }
        }

        if(temp) {
            cout << count << endl;
            continue;
        }

        if(flag) {
            if(k > 0) {
                cout << -1 <<endl;
                continue;
            }
            else{
                cout << count << endl;
                continue;
            }
        }

        if(k > 0) {
            cout << -1 << endl;
        }
        else{
            cout << count << endl;
        }
    }
    return 0;
}
