#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll answer(unordered_map <ll , ll> freq) {
    ll ans = 0 ,  val = 0;
    for(auto itr : freq) {
        if(itr.second >= val) {
            ans = itr.first;
            val = itr.second;
        }
    }
    return ans;
}
 int main() {
     ll t;
     cin >> t;
     while(t--) {
         ll n , m , k;
         cin >> n >> m >> k;
         ll ans[n] = {0};
         for(ll i = 0 ; i < n ; i++) {
             unordered_map <ll , ll> freq;
             for(ll j = 0 ; j < k ; j++) {
                 ll x;
                 cin >> x;
                 freq[x] ++;
             }
             ans[i] = answer(freq);
         }

         for(ll i = 0 ; i < n ; i++) {
             cout << ans[i] << " ";
         }
         cout << endl;
     }
     return 0;
 }
