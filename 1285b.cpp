#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll subArraySumFwd(ll arr[] , ll n) {
    ll cur = arr[0];
    ll sum = arr[0];
    for(ll i = 1 ; i < n - 1 ; i++) {
        cur = max(arr[i] , cur + arr[i]);
        sum =  max(sum , cur);
    }
    return sum;
}

ll subArraySumBwd(ll arr[] , ll n) {
    ll cur = arr[1];
    ll sum = arr[1];
    for(ll i = 2 ; i < n ; i++) {
        cur = max(arr[i] , cur + arr[i]);
        sum =  max(sum , cur);
    }
    return sum;
}

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

        ll adiel = 0;
        for(ll i = 0 ; i < n ; i++) {
            adiel += arr[i];
        }

        ll fwd = subArraySumFwd(arr , n);
        ll bwd = subArraySumBwd(arr , n);
        // cout << fwd << " " << bwd << endl;
        ll yasser = max(fwd , bwd);
        // cout << adiel << " " << yasser << endl;

        if(yasser >= adiel) {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}
