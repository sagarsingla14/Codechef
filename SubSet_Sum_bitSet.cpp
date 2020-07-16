#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};

    ll sum = 0;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    bitset <100000> bs;
    bs.set(0 , 1);

    for(ll i = 0 ; i < n ; i++) {
        bs |= (bs << arr[i]);
    }

    ll q;
    cin >> q;
    while(q--) {
        ll val;
        cin >> val;
        if(val > sum) {
            cout << "NO" << endl;
            continue;
        }
        if(bs[val]) {
            cout << "YES" << endl;
        }
        else{
             cout << "NO" << endl;
        }
    }
    return 0;
}
