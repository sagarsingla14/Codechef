#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INF 10000000000000

int main() {
    ll n;
    cin >> n;
    vector <ll> arr;
    for(ll i = 0 ; i < 2 * n ; i++) {
        ll x;
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin() , arr.end());

    ll cnt = 0;
    ll ans = 0;

    while(cnt < n - 1) {
        vector <ll> v;
        for(ll i = 0 ; i < arr.size() ; i++) {
            if(arr[i]) {
                v.push_back(arr[i]);
            }
        }

        ll index = -1 , mn = INF;
        for(ll i = 0 ; i < v.size() - 1 ; i++) {
            if(v[i + 1] - v[i] < mn) {
                mn = v[i + 1] - v[i];
                index = i;
            }
        }
        ans += mn;
        v[index] = 0 , v[index + 1] = 0;
        arr = v;
        cnt ++;
    }

    cout << ans << endl;
    return 0;
}
