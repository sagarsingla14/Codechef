#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;

        ll t1 = n, t2 = n;
        for(ll i = 0; i < (k - 1); i++){
            t1--;
            t2 -= 2;
        }

        if(t1 % 2 == 0 && t2 % 2 != 0)
            cout << "NO\n";
        else {
            if(t1 % 2 != 0 && t1 > 0){
                cout << "YES\n";
                for(ll i = 0; i < (k - 1); i++){
                    cout << "1 ";
                }
                cout << t1 << "\n";
            } else if(t2 % 2 == 0 && t2 > 0){
                cout << "YES\n";
                for(ll i = 0; i < (k - 1); i++){
                    cout << "2 ";
                }
                cout << t2 << "\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
