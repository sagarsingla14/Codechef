#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        sort(arr , arr + n);

        ll sum = 1;
        for(ll i = 0 ; i < n ; i++) {
            if(sum >= arr[i]) {
                sum ++;
            }
            else{
                ll temp = sum;
                ll j = i;
                ll flag = 1;
                while(j < n && flag) {
                    if(arr[j] <= temp) {
                        temp ++;
                        sum = temp;
                        flag = 0;
                        break;
                    }
                    else {
                        temp ++;
                    }
                    j ++;
                }
                i = j;
            }
        }

        cout << sum << endl;
    }
    return 0;
}