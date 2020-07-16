#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define in int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t-- ) {
        ll n , k;
        cin >> n >> k;
        ll div = n / k;
        ll rem = n % k;

        string str = "";
        for(ll i = 0 ; i < k ; i++) {
            for(ll j = 0 ; j < div ; j++) {
                str += ('a' + i);
            }
        }

        for(ll i = 0 ; i < rem ; i++) {
            str += ('a' + i);
        }

        cout << str << endl;
    }
    return 0;
}
