#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int

ld ncr[11][11];
ll power(ll x , ll y) {
    if(y == 0) {
        return 1;
    }
    ll pw = power(x , y / 2);
    if(y & 1) {
        return pw * pw * x;
    }
    else {
        return pw * pw;
    }
}

void calcNCR() {
    ncr[0][0] = 1;
    for(ll i = 0 ; i <= 10 ; i++) {
        ncr[i][0] = 1;
    }
    ncr[1][1] = 1;
    for(ll i = 2 ; i <= 10 ; i++) {
        for(ll j = 1 ; j <= i ; j++) {
            ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
        }
    }
}



int main() {
    memset(ncr , 0 , sizeof(ncr));
    calcNCR();
    string a , b;
    cin >> a >> b;
    ll l = a.length();
    map <char , ll> mpa;
    map <char , ll> mpb;

    for(ll i = 0 ; i < l ; i++) {
        mpa[a[i]] ++;
        mpb[b[i]] ++;
    }

    ll impos = 0;
    if(mpb['+'] > mpa['+']) {
        impos = 1;
    }
    else if(mpb['-'] > mpa['-']) {
        impos = 1;
    }
    else if(mpb['?'] == 0 && !impos) {
        ld x = 1;
        cout << fixed << setprecision(12) << x << endl;
    }
    else{

        ll x = mpb['?'];
        ll plus = mpa['+'] - mpb['+'];
        ll neg = mpa['-'] - mpb['-'];
        ll r = 0;
        if(plus != 0 && neg != 0) {
            r = plus;
        }
        else{
            if(plus) {
                r = plus;
            }
            else{
                r = neg;
            }
        }

        ll pw = power(2 , x);
        ld ans = 1.0 / pw;

        ans *= ncr[x][r];
        cout << fixed << setprecision(12) << ans << endl;
    }
    if(impos) {
        cout << fixed << setprecision(12) << 0.000000000000 << endl;
    }

    return 0;
}
