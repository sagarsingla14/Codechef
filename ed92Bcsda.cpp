#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        fast_io
        ll n , k , z;
        cin >> n >> k >> z;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        z = min(z , 5ll);

        ll dp[n] = {0};
        ll sum = 0;

        for(ll i = 0 ; i < n ; i++) {
            sum += arr[i];
            if(i == 0) {
                dp[i] = arr[i];
            }
            else{
                dp[i] = dp[i - 1] + arr[i];
            }
        }


        if(z == 0) {
            ll ans = 0;
            for(ll i = 0 ; i <= k ; i++) {
                ans += arr[i];
            }
            cout << ans << endl;
        }
        else{
            k --;
            vector <ll> v;
            ll ans = 0;
            ll ok = 0;
            sum = arr[0];

            for(ll i = 1 ; i < n ; i++) {
                if(k < 0) {
                    break;
                }
                else if(z == 0) {
                    sort(v.begin() , v.end());
                    ll ans = v[v.size() - 1];
                    for(ll j = i; j <= min(n - 1 , i + k) ; j++) {
                        ans += arr[j];
                    }
                    cout << ans << endl;
                    ok = 1;
                    break;
                }
                else {
                    ll tempK = k , tempZ = z;
                    sum += arr[i];
                    ll tempSum = sum;
                    bool left = true;
                    ll j = i;
                    while(tempZ > 0 && tempK > 0) {
                        if(left) {
                            j --;
                            tempZ --;
                            tempK --;
                            tempSum += arr[j];
                            left = false;
                        }
                        else {
                            tempK--;
                            j++;
                            tempSum += arr[j];
                            left = true;
                        }
                    }
                    if(tempK > 0) {
                        int range = min(n - 1 , j + tempK);
                        tempSum += (dp[range] - dp[j]);
                    }
                    v.push_back(tempSum);
                    k--;
                }
                if(ok) {
                    break;
                }
            }

            if(!ok) {
                sort(v.begin() , v.end());
                cout << v[v.size() -1] << endl;
            }
        }
    }
    return 0;
}
