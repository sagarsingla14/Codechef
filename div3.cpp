#include <bits/stdc++.h>
using namespace std;
#include <vector>
#define ll long long int
#include <map>
#define mod 1000000007
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll a , b , c , n;
        ll arr[3];
        for(ll i = 0 ; i < 3 ; i++) {
            cin >> arr[i];
        }
        sort(arr , arr + 3);
        cin >> n;
        ll count = 0;
        count += abs(arr[2] - arr[1]);
        count += abs(arr[2] - arr[0]);
        if(count > n) {
            cout <<"NO" << endl;
            continue;
        }
        n -= count;
        if(n % 3 == 0) {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

}
