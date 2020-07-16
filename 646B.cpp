#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        ll n = str.length();
        ll one = 0 , zero = 0;

        vector <ll> a , b;
        for(ll i = 0 ; i < n ; i++) {
            if(str[i] == '1') {
                one ++;
                a.push_back(i);
            }
            else{
                zero ++;
                b.push_back(i);
            }
        }

        if(one == n || zero == n || n <= 2) {
            cout << 0 << endl;
        }
        else{
            ll ok = 0;
            ll fa = 0 , fb = 0 , fc = 0;
            for(ll i = 0 ; i < n ; i++) {
                if(fa != 0) {
                    if(!fb) {
                        if(str[i] == '0') {
                            fb = 1;
                        }
                    }
                    else if(fc != 0){
                        if(!fc) {
                            if(str[i] == '1') {
                                fc = 1;
                            }
                        }
                    }
                }
                else if(fa == 0 && str[i] == '1'){
                    fa = 1;
                }
            }

            if(fa && fb && fc) {
                cout << 0 << endl;
            }
            else{
                fa = 0 , fb = 0 , fc = 0;
                for(ll i = 0 ; i < n ; i++) {
                    if(fa != 0) {
                        if(!fb) {
                            if(str[i] == '1') {
                                fb = 1;
                            }
                        }
                        else if(fc != 0){
                            if(!fc) {
                                if(str[i] == '0') {
                                    fc = 1;
                                }
                            }
                        }
                    }
                    else if(fa == 0 && str[i] == '0'){
                        fa = 1;
                    }
                }

                if(fa && fb && fc) {
                    cout << 0 << endl;
                }
                else{
                    ll ans = 0;
                    if(str[0] == str[n - 1]) {
                        if(str[0] == '1') {
                            cout << min(zero , one - 1) << endl;
                        }
                        else{
                            cout << min(zero - 1 , one) << endl;
                        }
                    }
                    else{
                        cout << min(zero  , one) - 1 << endl;
                    }
                }
            }
        }
    }
    return 0;
}
