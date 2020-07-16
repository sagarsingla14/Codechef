#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t , n , ans = 0 , temp = 0;
int main() {
    cin >> t;
    while(t--) {
        ans = 0 , temp = 1;
        cin >> n;
        ll arr[n] = {0};
        priority_queue <ll , vector <ll>  , greater <ll> > pq;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            // pq.emplace(arr[i]);
        }

        for(ll i = 0 ; i < n ; i++) {
            if(temp )
        }

        sort(arr , arr + n);
		cout << ans << endl;
    }
    return 0;
}
