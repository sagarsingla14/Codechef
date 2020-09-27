#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll ans = 0;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        string a , b;
        cin >> a >> b;

        ll present[26] = {0};
        for(ll i = 0 ; i < n ; i++) {
            present[a[i] - 'a'] ++;
        }

        ll ok = 1;
        for(ll i = 0 ; i < n ; i++) {
            if(b[i] < a[i]) {
                ok = 0;
                break;
            }
        }


        if(!ok) {
            cout << -1 << endl;
        }
        else{

            for(char i = 'a' ; i < 'z' ; i++) {
                if(mp[i]) {
                    set <ll> s;
                    for(ll j = 0 ; j < n ; j++) {
                        if(a[j] != b[j] && a[j] == i) {
                            s.insert(b[j]);
                        }
                    }
                    ans += s.size();
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
