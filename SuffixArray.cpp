#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    string str;
    cin >> str;
    str += "$";
    ll n = str.length();

    vector <pair <char , ll>> a;
    for(ll i = 0 ; i < n ; i++) {
        a.push_back({str[i] , i});
    }
    sort(a.begin() , a.end());

    vector <ll> p(n) , c(n);
    for(ll i = 0 ; i < n ; i++) {
        p[i] = a[i].second;
    }

    c[p[0]] = 0;
    for(ll i = 1 ; i < n ; i++) {
        if(a[i].first == a[i - 1].first) {
            c[p[i]] = c[p[i - 1]];
        }
        else{
            c[p[i]] = c[p[i - 1]] + 1;
        }
    }

    ll k = 0;
    while((1ll << k) < n) {
        vector <pair <pair <ll , ll> , ll>> a(n);
        for(ll i = 0 ; i < n ; i++) {
            a[i] = {{c[i] , c[(i + (1ll << k)) % n]} , i};
        }

        sort(a.begin() , a.end());

        for(ll i = 0 ; i < n ; i++) {
            p[i] = a[i].second;
        }

        c[p[0]] = 0;
        for(ll i = 1 ; i < n ; i++) {
            if(a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            }
            else{
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        k ++;
    }

    for(ll i = 0 ; i < n ; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
    return 0;
}
