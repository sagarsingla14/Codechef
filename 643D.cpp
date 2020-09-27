#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 9000000000000000000

ll arr[1000002] = {0};
ll a , b , c , d , ans = 0;

int main() {
    cin >> a >> b >> c >> d;
    for(ll i = a ; i <= b ; i++) {
        arr[b + i] ++;
        arr[c + i + 1] --;
    }

    for(ll i = 1 ; i <= 1000001 ; i++) {
        arr[i] += arr[i - 1];
    }
    for(ll i = 1 ; i <= 1000001 ; i++) {
        arr[i] += arr[i - 1];
    }

    ans = 0;
    for(ll i = d ; i >= c ; i--) {
        ans += arr[1000001] - arr[i];
    }
    cout << ans << endl;
}
