#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 100000000000000

bool check(ll arr[] , ll n , ll m , ll x) {
    ll cows = 1 , pos = arr[0];
	for(ll i = 1 ; i < n ; i++) {
		if(arr[i] - pos >= x) {
			pos = arr[i];
			cows ++;
			if(cows == m) {
                return true;
            }
		}
	}
	return false;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , m;
        cin >> n >> m;

        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        sort(arr , arr + n);

        ll f = 1 , l = arr[n - 1] , ans = 1;
        while(f <= l) {
            ll mid = (f + l) >> 1ll;
            if(check(arr , n , m , mid)) {
                ans = mid;
                f = mid + 1;
            }
            else{
                l = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
