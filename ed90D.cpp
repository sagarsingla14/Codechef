#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n;

ll calcEven(ll arr[]) {
    vector <ll> dp;

    dp.push_back(0);
    for(ll i = 0 ; i < n - 1 ; i += 2) {
        dp.push_back(arr[i + 1] - arr[i]);
    }

    cout << "calc even ";
    for(auto i : dp) {
        cout << i << " ";
    }
    cout << endl;

    for(ll i = 1 ; i < dp.size() ; i++) {
        dp[i] = max(dp[i - 1] + dp[i] , dp[i]);
    }

    ll mx = 0;
    for(ll i = 0 ; i < dp.size() ; i++) {
        mx = max(mx , dp[i]);
    }

    for(auto i : dp) {
        cout << i << " ";
    }
    cout << endl;

    return mx;
}

ll calcOdd(ll arr[]) {
    vector <ll> dp;
    dp.push_back(0);

    for(ll i = 1 ; i < n - 1 ; i += 2) {
        dp.push_back(arr[i] - arr[i + 1]);
    }

    cout << "calc odd ";
    for(auto i : dp) {
        cout << i << " ";
    }
    cout << endl;

    for(ll i = 1 ; i < dp.size() ; i++) {
        dp[i] = max(dp[i - 1] + dp[i] , dp[i]);
    }

    for(auto i : dp) {
        cout << i << " ";
    }
    cout << endl;

    ll mx = 0;
    for(ll i = 0 ; i < dp.size() ; i++) {
        mx = max(mx , dp[i]);
    }

    return mx;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        cin >> n;
        ll arr[n] = {0};
        ll sum = 0;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            if(i % 2 == 0) {
                sum += arr[i];
            }
        }
        if(n == 1) {
            cout << arr[0] << endl;
        }
        else if(n == 2) {
            cout << max(arr[0] , arr[1]) << endl;
        }
        else{
            ll sumA = calcEven(arr);
            ll sumB = calcOdd(arr);

            ll rarr[n] = {0};
            ll j = n - 1;
            for(ll i = 0 ; i < n ; i++) {
                rarr[j] = arr[i];
                j --;
            }

            // ll sumC = calcEven(rarr);
            // ll sumD = calcOdd(rarr);

            ll addSum = 0;
            addSum = max(addSum , sumA);
            addSum = max(addSum , sumB);
            // addSum = max(addSum , sumC);
            // addSum = max(addSum , sumD);

            ll ans = addSum + sum;

            cout << ans << endl;
        }
    }
    return 0;
}
