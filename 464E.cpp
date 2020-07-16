#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

vector <ld> v(1);
ld dp[500001];
ll q;
ld x , add;

void setDp() {
    ll i = v.size();
    i --;
    ld prevSum = (dp[i - 1] * (i - 1));
    ld newSum = prevSum + v[i];
    newSum /= (1.0 * i);
    dp[i] = newSum;
}

void calcAns() {
    ld ans = 0;
    ll sze = v.size();
    sze --;

    ld mean = v[sze] + v[1];
    mean /= 2.0;

    auto i = upper_bound(v.begin() , v.end() , mean) - v.begin();
    i --;
    ld subsetMean = dp[i];
    subsetMean *= (1.0 * i);
    subsetMean += v[sze];
    subsetMean /= (1.0 * (i + 1));

    ans = v[sze] - subsetMean;

    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
    fast_io
    cin >> q;
    memset(dp , 0 , sizeof(dp));

    while(q--) {
        cin >> x;
        if(x == 1) {
            cin >> add;
            v.push_back(add);
            setDp();
        }
        else {
            calcAns();
        }
    }
    return 0;
}
