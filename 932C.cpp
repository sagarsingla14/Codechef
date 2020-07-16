#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll findSubarraySum(ll arr[], ll n, ll sum) {
    unordered_map<ll , ll> prevSum;
    ll res = 0;
    ll currsum = 0;
    for (int i = 0; i < n; i++) {
        currsum += arr[i];
        if (currsum == sum)
            res++;
        if (prevSum.find(currsum - sum) !=
                                  prevSum.end())
            res += (prevSum[currsum - sum]);
        prevSum[currsum]++;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    ll sum = 0;
    ll minus = findSubarraySum(arr , n , sum);
    cout << minus << endl;
    ll ans = (n * (n + 1)) / 2;
    cout << ans - minus << endl;
    return 0;
}
