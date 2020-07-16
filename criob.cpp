#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll m , n , k;
    cin >> m >> n >> k;
    map <ll , ll> map1,map2;
    vector <ll> mat[m];
    ll count = 0;
    for(ll i = 0; i < m; i++){
        for(ll j = 0; j < n; j++){
            ll x;
            cin >> x;
            mat[i].push_back(x);
            if(mat[i][j] == 1){
                count += map1[i+j]++;
                count += map2[i-j]++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
