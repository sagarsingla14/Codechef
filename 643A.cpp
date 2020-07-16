#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll n , k , ans = 0;
ll ok = 0;
ll t;

ll add = 0;
void dig(ll a) {
    ll x = 0 , y = 9;
    add = 0;
    while(a > 0){
        ll r = a % 10 ;
        y = min(y , r);
        x = max(x , r);
        a /= 10;
    }
    if(x * y == 0) {
        ok = 0;
    }
    add = x * y;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        ans = n;
        k --;
        while(k--) {
            ok = 1;
            dig(ans);
            if(!ok) {
                break;
            }
            ans += (add);
            add = 0;
        }
        cout << ans << endl;
    }
    return 0;
}
