#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INF 10000000000000

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        ll dp[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            if(arr[i] == i + 1) {
                dp[i] = 1;
            }
        }
        ll check = 0;
        ll f = 0 , l = n - 1;
        while(f < n && dp[f]) {
            f ++;
        }
        while(l >= 0 && dp[l]) {
            l --;
        }
        if(l < f) {
            check = 2;
        }
        for(ll i = f ; i <= l ; i++) {
            if(dp[i]) {
                check = 1;
                break;
            }
        }
        if(check == 1) {
            cout << 2 << endl;
        }
        else if(check == 2){
            cout << 0 << endl;
        }
        else{
            cout << 1 << endl;
        }
    }
    return 0;
}
