#include <iostream>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }

        ll mask = 0;
        for(ll i = 31 ; i >= 0 ; i--) {
            ll tempMask = mask | (1ll << i);
            ll cnt = 0;
            for(ll j = 0 ; j < n ; j++) {
                if((arr[j] & tempMask) == tempMask) {
                    cnt ++;
                }
            }
            if(cnt >= 2) {
                mask = mask | (1ll << i);
            }
        }

        cout << mask << endl;
    }
    return 0;
}
