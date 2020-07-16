#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fast_io
    ll n;
    cin >> n;

    ll arr[n + 1] = {0};
    for(ll i = 0 ; i <= n ; i++) {
        cin >> arr[i];
    }

    priority_queue <pair <ll , ll> > pq;

    ll mx = -100;
    ll sum = arr[i];
    ll dp[n + 1] = {0};
    dp[1] = arr[1];

    for(ll i = 2 ; i <= n ; i++) {
        sum = max(sum , dp[i - 1] + arr[i]);
        dp[i] = sum;
        if(sum < 0) {
            pq.push_back(sum , )
        }
        else {
            mx = max(mx , arr[i]);
        }
    }

    return 0;
}
