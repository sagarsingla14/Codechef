#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n;
ll arr[10] = {0};

int main() {
    cin >> n;
    for(ll i = 0 ; i < 10 ; i++) {
        arr[i] = 1;
    }
    string str = "codeforces";

    ll ans = 1;
    ll flag = 0;
    while(ans < n && flag == 0) {
        for(ll i = 0 ; i < 10 ; i++) {
            arr[i] ++;
            ll product = 1;
            for(ll j = 0 ; j < 10 ; j++) {
                product *= arr[j];
            }
            if(product >= n) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            break;
        }
    }

    for(ll i = 0 ; i < 10 ; i++) {
        for(ll j = 0 ; j < arr[i] ; j++) {
            cout << str[i];
        }
    }
    cout << endl;

    return 0;
}
