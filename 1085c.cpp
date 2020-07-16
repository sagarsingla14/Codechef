#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
ll degree[100001];
ll n , sum;

int main() {
    cin >> n >> sum;

    memset(degree , 0 , sizeof(degree));
    for(ll i = 0 ; i < n - 1 ; i++) {
        ll u , v;
        cin >> u >> v;
        degree[u] ++;
        degree[v] ++;
    }
    ld nodes = 0;
    for(auto i : degree) {
        if(i == 1) {
            nodes ++;
        }
    }

    ld ans = sum / nodes;
    ans *= 2.0;
    cout << fixed << setprecision(18) << ans << endl;

    return 0;
}
