#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int max(int a, int b) { return (a > b)? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W
ll knapSack(ll W, ll wt[], ll val[], ll n) {
   ll i, w;
   ll K[n+1][W+1];
   for (i = 0; i <= n ; i++) {
       for (w = 0; w <= W; w++) {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , w , x , y;
        cin >> n >> w >> x >> y;
        ll wt[n] = {0};
        ll val[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> wt[i];
        }
        for(ll i = 0 ; i < n ; i++) {
            cin >> val[i];
        }
        ll W = w;
        ll ans = knapSack(W, wt, val, n);
        cout << ans << endl;
    }
    return 0;
}
