#include <bits/stdc++.h>
#define ll long long int
#define train_choot_jayegi ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;
int main() {
    train_choot_jayegi
    
    ll n , k;
    cin >> n >> k;
    ll arr[n + 1] = {0};
    ll sum[n + 1] = {0};
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }

    for(ll i = 1 ; i <= n ; i++) {
        sum[i] += sum[i - 1] + arr[i];
    }

    ll ans = -1;
    ll index = -1;
    for(ll i = 1 ; i <= n - k ; i++) {
        ll end = i + k - 1;
        if(end > n - k) {
            break;
        }
        ll val = abs(sum[end] - sum[i - 1]);
        if(val > ans) {
            ans = val;
            index = i;
        }
    }

    ll index2 = -1;
    ans = -1;
    for(ll i = index + k ; i <= n ; i++) {
        ll end = i + k - 1;
        if(end > n) {
            break;
        }
        ll val = abs(sum[end] - sum[i - 1]);
        if(val > ans) {
            ans = val;
            index2 = i;
        }
    }

    cout << index << " " << index2 << endl;
    return 0;
}
