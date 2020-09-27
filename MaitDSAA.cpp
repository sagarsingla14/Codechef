#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int calc(int x) {
    ll sum = 0;
    while(x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

char dp[2][2];

int main() {
    ll t;
    memset(dp , '0' , sizeof(dp));
    cout << dp[0][0] << endl;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        int arr[n] = {0};
        for(int i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        sort(arr , arr + n);
        map <int , vector <int> > mp;
        for(int i = 0 ; i < n ; i++) {
            int sum = calc(arr[i]);
            mp[sum].push_back(arr[i]);
        }

        int ans = 0;
        for(auto i : mp) {
            vector <int> v = i.second;
            if(v.size() > 1) {
                ans = max(ans , v[v.size() - 1] + v[v.size() - 2]);
            }
        }
        if(ans) {
            cout << ans << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}
