#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// Sliding Window

int main() {
    ll n , k;
    cin >> n >> k;
    ll sum = 0;
    ll index = 0;
    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        if(i < k) {
            sum += arr[i];
        }
    }
    ll mn = sum;
    for(ll i = 1 ; i <= n - k ; i++) {
        sum -= arr[i - 1];
        sum += arr[i + k - 1];
        if(sum <= mn) {
            mn = sum;
            index = i;
        }
    }
    cout << index + 1 << endl;
    return 0;
}
