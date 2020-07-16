#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n , one , zero , group , zeroPerGroup , groupsWithExtraZero , t;
vector <ll> res;
ll ans = 0;

void solve() {
    zero = n - one;
    group = one + 1;
    ans = (n * (n + 1)) / 2ll;
    zeroPerGroup = zero / group;
    ans -= ((zeroPerGroup * (zeroPerGroup + 1)) / 2) * group;
    groupsWithExtraZero = zero % group;
    ans -= (zeroPerGroup + 1) * groupsWithExtraZero;
}

void input() {
    cin >> t;
    while(t--) {
        cin >> n >> one;
        solve();
        res.push_back(ans);
    }
}

void printAnswer() {
    for(auto i : res) {
        cout << i << endl;
    }
}

int main() {
    input();
    solve();
    printAnswer();
}
