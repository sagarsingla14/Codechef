#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define INFI 1000000000000000000

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll arr[4] = {0};
        ll brr[4] = {0};

        ll mn = INFI;
        ll sum = 0;
        for(ll i = 0 ; i < 4 ; i ++) {
            cin >> arr[i];
            brr[i] = arr[i];
            sum += arr[i];
            if(i < 3) {
                mn = min(mn , arr[i]);
            }
        }

        ll ok = 1;
        if(sum % 2) {
            ll cnt = 0;
            for(ll i = 0 ; i < 3 ; i++) {
                brr[i] -= mn;
                brr[3] += mn;
            }

            for(ll i = 0 ; i < 4 ; i++) {
                if(brr[i] % 2) {
                    cnt ++;
                }
            }

            if(cnt > 1) {
                ok = 0;
            }
            if(!ok && mn > 0) {
                ok = 1 , cnt = 0;
                for(ll i = 0 ; i < 4 ; i++) {
                    brr[i] = arr[i];
                }
                for(ll i = 0 ; i < 3 ; i++) {
                    brr[i] -= (mn - 1);
                    brr[3] += (mn - 1);
                }
                for(ll i = 0 ; i < 4 ; i++) {
                    if(brr[i] % 2) {
                        cnt ++;
                    }
                }

                if(cnt > 1) {
                    ok = 0;
                }
            }
        }
        else {
            for(ll i = 0 ; i < 3 ; i++) {
                brr[i] -= mn;
                brr[3] += mn;
            }

            for(ll i = 0 ; i < 4 ; i++) {
                if(brr[i] % 2) {
                    ok = 0;
                    break;
                }
            }

            if(!ok && mn > 0) {
                ok = 1;
                for(ll i = 0 ; i < 4 ; i++) {
                    brr[i] = arr[i];
                }
                for(ll i = 0 ; i < 3 ; i++) {
                    brr[i] -= (mn - 1);
                    brr[3] += (mn - 1);
                }
                for(ll i = 0 ; i < 4 ; i++) {
                    if(brr[i] % 2) {
                        ok = 0;
                        break;
                    }
                }
            }
        }

        if(ok) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}
