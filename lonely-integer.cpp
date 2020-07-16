#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n , m , ans , lib , road;
vector <ll> graph[100001];
ll visited[100001];
ll degree[100001];

ll findMSB(ll x) {
    ll msb = 0;
    while(x) {
        msb ++;
        x >>= 1;
    }
    return msb;
}


int main() {
    ll l , r;
    cin >> l >> r;
    ll xr = l ^ r;
    if(l == r) {
        cout << 0 << endl;
    }
    else{
        ll msb = findMSB(xr);
        cout << pow(2 , msb) - 1 << endl;
    }
    return 0;
}
