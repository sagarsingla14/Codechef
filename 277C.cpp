#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n , k;
    string str;
    cin >> n >> k >> str;
    k --;

    ll left = 0 , right = 0;
    if(n % 2) {
        if(n / 2 >= k) {
            left = 1;
        }
        else {
            right = 1;
        }
    }
    else {
        if(n / 2 > k) {
            left = 1;
        }
        else {
            right = 1;
        }
    }

    vector <ll> arr(n , 0);
    ll ans = 0;

    if(left) {
        for(ll i = 0 ; i < n / 2 ; i++) {
            ll a = abs(str[i] - str[n - i - 1]);
            ll b = abs(str[i] - 'a') + abs(str[n - i - 1] - 'z') + 1;
            ll bb = abs(str[i] - 'z') + (abs(str[n - i - 1] - 'a')) + 1;
            b = min(b , bb);

            arr[i] = min(a , b);
            ans += arr[i];
        }


        ll f = -1 , l = -1;
        for(ll i = 0 ; i < n ; i++) {
            if(arr[i]) {
                f = i;
                break;
            }
        }
        for(ll i = n - 1 ; i >= 0 ; i--) {
            if(arr[i]) {
                l = i;
                break;
            }
        }

        if(l != -1 && f != -1) {
            ans += abs(f - l);
            ans += (min(abs(k - l) , abs(k - f)));
        }
    }
    else if(right) {
        for(ll i = n / 2 ; i < n ; i++) {
            ll a = abs(str[i] - str[n - i - 1]);
            ll b = abs(str[i] - 'a') + (abs(str[n - i - 1] - 'z')) + 1;
            ll bb = abs(str[i] - 'z') + (abs(str[n - i - 1] - 'a')) + 1;
            b = min(b , bb);

            arr[i] = min(a , b);
            ans += arr[i];
        }

        ll f = -1 , l = -1;
        for(ll i = 0 ; i < n ; i++) {
            if(arr[i]) {
                f = i;
                break;
            }
        }
        for(ll i = n - 1 ; i >= 0 ; i--) {
            if(arr[i]) {
                l = i;
                break;
            }
        }

        if(l != -1 && f != -1) {
            ans += abs(f - l);
            ans += (min(abs(k - l) , abs(k - f)));
        }
    }
    cout << ans << endl;

    return 0;
}
