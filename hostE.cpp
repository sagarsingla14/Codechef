#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , k;

int main() {
    cin >> n >> k;
    ll arr[n] = {0};

    ll total = 0;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    for(ll i = 1 ; i < n ; i++) {
        arr[i] += arr[i - 1];
    }

    ll q[k] = {0};

    for(ll i = 0 ; i < k ; i++) {
        cin >> q[i];
    }
    ll i = 0 , j = 0;

    ll sum = 0;
    vector <ll> ans;

    while(j < k) {
        sum += q[j];
        auto index  = upper_bound(arr , arr + n , sum) - arr;
        if(index == n) {
            ans.push_back(n);
            sum = 0;
            j ++;
            i = 0;
        }
        else {
            ans.push_back(n - index);
             i ++;
             j ++;
        }
    }

    for(auto i : ans) {
        cout << i << endl;
    }
    cout << endl;
    return 0;
}
