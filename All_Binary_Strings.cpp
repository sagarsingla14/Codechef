#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(ll index , ll arr[] , ll n) {
    if(index == 0) {
        for(ll i = 0 ; i < n ; i++) {
            cout << arr[i];
        }
        cout << endl;
        return ;
    }

    arr[index - 1] = 0;
    solve(index - 1 , arr , n);
    arr[index - 1] = 1;
    solve(index - 1 , arr , n);
}

int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};
    solve(n , arr , n);
}
