#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

ll n;
ll arr[100001] = {0};

int main() {
    fast_io
    cin >> n;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    sort(arr , arr + n);
    ll sum = 0;
    ll cnt = 0;

    for(ll i = 0 ; i < n ; i++) {
        if(sum <= arr[i]) {
            cnt ++;
            sum += arr[i];
        }
    }

    cout << cnt << endl;
    return 0;
}
