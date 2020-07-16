#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int longestMountain(vector<int>& arr) {
    ll n = arr.size();
    if(n == 1 || n == 2) {
        return 0;
    }
    // 8
    // 2 1 4 7 8 8 4 3
    ll dp[n - 1];
    for(ll i = 1 ; i < n ; i++) {
        dp[i - 1] = arr[i] - arr[i - 1];
    }

    for(auto i : dp) {
        cout << i << " ";
    }
    cout << endl;

    ll pos = 0 , neg = 0 , ans = 0;
    for(ll i = 0 ; i < n - 1 ; i++) {
        ll cntpos = 0;
        ll cntneg = 0;
        ll j = i;

        if(dp[i] == 0) {
            continue;
        }

        while(dp[j] > 0 && j < n - 1)  {
            cntpos ++;
            j ++;
        }
        while(dp[j] < 0 && j < n - 1) {
            cntneg ++;
            j ++;
        }
        i = j;
        i -- ;

        if(cntpos && cntneg) {
            ans = max(ans , cntpos + cntneg + 1);
        }
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    vector <ll> arr(n);

    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    cout << longestMountain(arr) << endl;

    return 0;
}
