#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};
    ll left[n] = {0};
    ll right[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        left[i] = 1;
        right[i] = 1;
    }
    for(ll i = 1 ; i < n ; i++) {
        if(arr[i] > arr[i - 1]) {
            left[i] += left[i - 1];
        }
    }
    // for(ll i = 0 ; i < n ; i++) {
    //     cout << left[i] << " ";
    // }
    // cout << endl;

    for(ll i = n - 2 ; i >= 0 ; i--) {
        if(arr[i] < arr[i + 1]) {
            right[i] += right[i + 1];
        }
    }
    // for(ll i = 0 ; i < n ; i++) {
    //     cout << right[i] << " ";
    // }
    // cout << endl;
    ll mx = 1;
    for(ll i = 1 ; i < n - 1 ; i++) {
        if(arr[i + 1] > arr[i - 1]) {
            mx = max(mx , left[i - 1] + right[i + 1]);
        }
    }

    for(ll i = 0 ; i < n ; i++) {
        mx = max(mx , left[i]);
    }
    cout << mx << endl;
    return 0;
 }
