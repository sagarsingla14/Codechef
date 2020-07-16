#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n ,k;
        cin >> n >> k;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++){
            cin >> arr[i];
        }

        if(k <= n) {
            for(ll i = 0 ; i < k ; i++) {
                arr[i] = arr[i] ^ arr[n - i - 1];
            }
            for(ll i = 0 ; i < n ; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else{
            vector <ll> v1,v2,v3;
            ll temp[n] = {0};

            for(ll i = 0 ; i < n ; i++) {
                temp[i] = arr[i];
            }

            for(ll i = 0; i < n ; i++) {
                ll a,b;
                a = temp[i];
                b = temp[n - i - 1];
                v1.push_back(a ^ b);
                temp[i] = v1[i];

            }

            for(ll i = 0; i < n ; i++) {
                ll a,b;
                a = temp[i];
                b = temp[n - i - 1];
                v2.push_back(a ^ b);
                temp[i] = v2[i];
                // cout << v2[i] << " ";
            }
            // cout << endl;

            for(ll i = 0; i < n ; i++) {
                ll a,b;
                a = temp[i];
                b = temp[n - i - 1];
                v3.push_back(a ^ b);
                temp[i] = v3[i];
                // cout << v3[i] << " ";
            }
            // cout << endl;

            ll num = k / n;
            num %= 3;
            ll mod = k % n;
            if(mod == 0) {
                vector <ll> result;
                if(num == 0) {
                    result = v3;
                }
                else if (num == 1){
                    result = v1;
                }
                else{
                    result = v2;
                }

                for(ll i = 0 ; i < result.size() ; i++) {
                    cout << result[i] << " ";
                }
                cout << endl;

            }
            else{
                vector <ll> result;
                if(num == 0) {
                    result = v3;
                }
                else if (num == 1){
                    result = v1;
                }
                else{
                    result = v2;
                }

                for(ll i = 0 ; i < mod ; i++) {
                    ll a = result[i];
                    ll b = result[n - i - 1];
                    result[i] = a ^ b;
                }

                for(ll i = 0 ; i < n ; i++) {
                    cout << result[i] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
