#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define INFI 1000000000000000000

void solve(ll m) {
    ll h = m / 60;
    ll min = m % 60;
    cout << h << " hours " << min << " minutes" << endl;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        string a , b;
        cin >> a >> b;
        ll h1 = 0 , m1 = 0 , h2 = 0 , m2 = 0;
        for(ll i = 0 ; i < 5 ; i++) {
            if(i < 2) {
                h1 *= 10;
                h2 *= 10;
                h1 += (a[i] - '0');
                h2 += (b[i] - '0');
            }
            if(i > 2) {
                m1 *= 10;
                m2 *= 10;
                m1 += (a[i] - '0');
                m2 += (b[i] - '0');
            }
        }

        ll t1 = h1 * 60 + m1;
        ll t2 = h2 * 60 + m2;

        if(t2 >= t1) {
            ll diff = t2 - t1;
            solve(diff);
        }
        else{
            t2 += 1440;
            ll diff = t2 - t1;
            solve(diff);
        }
    }
    return 0;
}
