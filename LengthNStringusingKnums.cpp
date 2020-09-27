#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , k;
void solve(ll arr[] , ll index) {
    if(index == 0) {
        for(ll i = 0 ; i < n ; i++) {
            cout << arr[i];
        }
        cout << endl;
        return ;
    }

    for(ll i = 0 ; i < k ; i ++) {
        arr[index - 1] = i;
        solve(arr , index - 1);
    }
}

int main() {
    cin >> n >> k;
    ll arr[n] = {0};
    solve(arr , n);
}
