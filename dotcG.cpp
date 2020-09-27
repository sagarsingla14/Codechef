#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 9000000000000000000

int main() {
    ll n , k;
    cin >> n >> k;
    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    vector <pair <ll , ll>> v;
    if(k == 1) {
        ll sum = 0;
        for(ll i = 0 ; i < n ; i++) {
            sum += arr[i];
        }

        ll mx = INFI;
        ll ans = -1;
        for(ll i = 500000 ; i >= -500000 ; i--) {
            ll cur = n * i - sum;
            if(cur >= 0) {
                if(cur <= mx) {
                    mx = cur;
                    ans = i;
                }
            }
        }
        ll x = ans , y = ans + 1 , z = ans - 1;
        ll vx = 0 , vy = 0, vz = 0;

        for(ll i = 0 ; i < n ; i++) {
            vx += abs(x - arr[i]);
            vy += abs(y - arr[i]);
            vz += abs(z - arr[i]);
            v.push_back({vx , x});
            v.push_back({vy , y});
            v.push_back({vz , z});
        }
        sort(v.begin() , v.end());
        cout << v[0].second << endl;
    }
    else if(k == 2) {
        ll sum = 0 , suma = 0;
        for(ll i = 0 ; i <  n ; i++) {
            sum += arr[i] * arr[i];
            suma += arr[i];
        }

        ll mx = INFI;
        ll ans = -1;
        for(ll i = 500000 ; i >= -500000 ; i--) {
            ll cur = n * i * i + sum - i * (2 * suma);
            if(cur >= 0) {
                if(cur <= mx) {
                    mx = cur;
                    ans = i;
                }
            }
        }

        ll x = ans , y = ans + 1, z = ans - 1;
        ll vx = 0 , vy = 0, vz = 0;

        for(ll i = 0 ; i < n ; i++) {
            vx += abs(x - arr[i]) * abs(x - arr[i]);
            vz += abs(z - arr[i]) * abs(z - arr[i]);
            vy += abs(y - arr[i]) * abs(y - arr[i]);
            v.push_back({vx , x});
            v.push_back({vy , y});
            v.push_back({vz , z});
        }
        sort(v.begin() , v.end());
        cout << v[0].second << endl;
    }
    else{
        ll sum = 0 , suma = 0 , sumb = 0;
        for(ll i = 0 ; i <  n ; i++) {
            sum += arr[i] * arr[i] * arr[i];
            suma += arr[i];
            sumb += arr[i] * arr[i];
        }

        ll mx = INFI;
        ll ans = -1;
        for(ll i = 500000 ; i >= -500000 ; i--) {
            ll cur = n * i * i * i - sum - i * i * 2 * suma + i * 3 * sumb;
            if(cur >= 0) {
                if(cur <= mx) {
                    mx = cur;
                    ans = i;
                }
            }
        }

        ll x = ans , y = ans + 1, z = ans - 1;
        ll vx = 0 , vy = 0 , vz = 0;

        for(ll i = 0 ; i < n ; i++) {
            vx += abs(x - arr[i]) * abs(x - arr[i]) * abs(x - arr[i]);
            vy += abs(y - arr[i]) * abs(y - arr[i]) * abs(y - arr[i]);
            vz += abs(z - arr[i]) * abs(z - arr[i]) * abs(z - arr[i]);
            v.push_back({vx , x});
            v.push_back({vy , y});
            v.push_back({vz , z});
            sort(v.begin() , v.end());
            cout << v[0].second << endl;
        }
    }
    return 0;
}
