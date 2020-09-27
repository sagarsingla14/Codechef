#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n;
    cin >> n;

    vector <ll> v(n + 1 , 0);

    ll a , b;
    for(ll i = 1 ; i < n ; i++) {
        cout << '?' << " " << i << " " << (i + 1) << endl;
        // fflush(stdout);

        cin >> a;
        if(a == -1) {
            return 0;
        }

        cout << '?' << " " << i + 1 << " " << i << endl;
        // fflush(stdout);

        cin >> b;
        if(b == -1) {
            return 0;
        }

        if(b > a) {
            v[i + 1] = b;
        }
        else{
            v[i] = a;
        }
    }


    ll ok = 0;
    if(v[1])  {
        ok = 1;
    }

    if(ok) {
        cout << '?' << " " << 1 << " " << n << endl;
        cin >> a;
        if(a == -1) {
            return 0;
        }
        v[1] = a;
    }
    else{
        cout << '?' << " " << 1 << " " << n << endl;
        cin >> b;
        if(b == -1) {
            return 0;
        }
        v[n] = b;
    }

    map <ll , ll> mp;
    vector <ll> rem;

    for(ll i = 1 ; i <= n ; i++) {
        mp[v[i]] = 1;
    }

    for(ll i = 1 ; i <= n ; i++) {
        if(mp[i] == 0) {
            rem.push_back(i);
        }
    }

    ll ind = 0;
    for(ll i = 1 ; i <= n ; i++) {
        if(!v[i]) {
            v[i] = rem[ind];
            ind ++;
        }
    }

    cout << "! ";
    for(ll i = 1 ; i <= n ; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    // fflush(stdout);

    return 0;
}
