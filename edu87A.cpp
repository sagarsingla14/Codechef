#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a ,b ,c ,d;
int main() {
    ll t;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d;
        if(b >= a){
            cout << b << endl;
        }
        else if(d >= c){
            cout << "-1" << endl;
        }
        else{
            ll x = ceil(double(a - b) / double(c - d));
            if(x >= 0){
                cout << (b + (x * c)) << endl;
            }
            else{
                cout << "-1" << endl;
            }
        }
    }
    return 0;
}
