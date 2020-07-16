#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    sort(arr , arr + n);
    if(arr[n - 1] < 0) {
        // Idhr Mara 
        for(ll i = n - 1 ; i >= 0 ; i--) {
            if(arr[i] & 1) {
                cout << arr[i] << endl;
                break;
            }
        }
    }
    else{
        ll sum = 0;
        vector <ll> o , e;
        for(ll i = n - 1 ; i >= 0 ; i--) {
            if(arr[i] & 1) {
                o.push_back(arr[i]);
            }
            else{
                e.push_back(arr[i]);
            }
            if(arr[i] >= 0) {
                sum += arr[i];
            }
        }

        sort(o.begin() , o.end());
        sort(e.begin() , e.end());

        if(sum & 1) {
            cout << sum << endl;
        }
        else {
            ll ans = sum;
            for(ll i = 0 ; i < o.size() ; i++) {
                if(o[i] > 0) {
                    ans -= o[i];
                    break;
                }
            }

            for(ll i = o.size() - 1 ; i >= 0 ; i--) {
                if(o[i] < 0) {
                    sum += o[i];
                    break;
                }
            }

            if((ans & 1) && (sum & 1))  {
                cout << max(ans , sum) << endl;
            }
            else {
                if(ans & 1) {
                    cout << ans << endl;
                }
                else{
                    cout << sum << endl;
                }
            }
        }
    }
    return 0;
}
