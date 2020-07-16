#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <map>
#define base 1000000007
#define ll long long int
int main(){
    ll n;
    cin >> n;
    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    if(n % 2 && arr[0] % 2 && arr[n- 1] % 2) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
