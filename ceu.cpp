#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        string a , b;
        cin >> a >> b;
        ll la = a.length();
        ll lb = b.length();
        map <char ,  ll> freq;

        vector <ll> v[26];
        for(ll i = 0 ; i < la ; i++) {
            freq[a[i]] = 1;
        }

        for(ll i = 0 ; i < la ; i++) {
            v[a[i] - 'a'].push_back(i);
        }

        ll flag = 0;
        for(ll i = 0 ; i < lb ; i++) {
            if(freq[b[i]] == 0) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            cout << -1 << endl;
        }
        else {
            ll present = -1;
            ll ans = 1;
            for(ll i = 0 ; i < lb ; i++) {
                char c = b[i];
                ll ss = v[c - 'a'].size();
                ll temp = 0;
                for(ll j = 0 ; j < ss ; j++){
                    if(v[c - 'a'][j] > present) {
                        present = v[c - 'a'][j];
                        temp = 1;
                        break;
                    }
                }

                if(!temp) {
                    ans ++;
                    present = v[c - 'a'][0];
                }
            }

            cout << ans << endl;
        }
    }
    return 0;
}
