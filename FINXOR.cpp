#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;

        ll sum = 0;
        for(ll i = 0 ; i <= 19 ; i++) {
            sum += (1 << i);
        }

        ll num = sum;

        vector <ll> v;
        ll q;

        num --;
        cout << 1 << " " << num << endl;
        cin >> q;

        v.push_back(q);
        for(ll i = 1 ; i <= 18 ; i++) {
            num -= (1 << i);
            cout << 1 << " " << num << endl;

            cin >> q;

            v.push_back(q);

            if(q == -1) {
                return 0;
            }
        }

        cout << 1 << " " << (1 << 20) << endl;

        cin >> q;
        q -= n * (1 << 20);
        if(q == -1) {
            return 0;
        }
        v.push_back(q);

        ll ans = 0;
        if(v[0] % 2) {
            ans += 1;
        }

        ll half = n / 2;
        if(n % 2) {
            half ++;
        }

        for(ll i = 1 ; i < 3 ; i++) {
            ll diff = v[i] - v[i - 1];
            if(diff > 0) {
                ll val = diff / (1 << i);
                if(val == n) {
                    if(n % 2) {
                        ans += (1 << i);
                    }
                }
                else{
                    if(val % 2 == 0) {
                        ans += (1 << i);
                    }
                }
            }
            else if(diff < 0) {
                ll val = diff / (1 << i);
                if(abs(val) == n) {
                    continue;
                }
                else{
                    if(val % 2) {
                        ans += (1 << i);
                    }
                }
            }
            else if(diff == 0){
                if(half % 2) {
                    ans += (1 << i);
                }
            }
        }
        cout << 2 << " " << ans << endl;

        ll x;
        cin >> x;

        if(x == -1) {
            return 0;
        }
    }
    return 0;
}


// ye bna ke differnce le rha hu or uspe bht sari conditons lga rkhi h

// 1111111110
// 1111111100
// 1111111000
// 1111110000
// 1111100000
// 1111000000
// 1110000000
// 1100000000
// 1000000000
