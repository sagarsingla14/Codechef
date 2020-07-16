#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll CeilIndex(std::vector<ll>& v, ll l, ll r, ll key)
{
    while (r - l > 1) {
        ll m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}

ll LongestIncreasingSubsequenceLength(std::vector<ll>& v)
{
    if (v.size() == 0)
        return 0;

    std::vector<ll> tail(v.size(), 0);
    ll length = 1;

    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {

        if (v[i] < tail[0])
            tail[0] = v[i];

        else if (v[i] > tail[length - 1])
            tail[length++] = v[i];

        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
    }
    return length;
}

ll lislength(ll arr[] , ll n) {
    ll lis[n] = {0};

    for(ll i = 0 ; i < n ; i++) {
        lis[i] = 1;
    }

    for(ll i = 0 ; i < n - 1 ; i++ ) {
        for(ll j = i + 1 ; j < n ; j++) {
            if(arr[i] < arr[j]) {
                lis[j] = max(lis[i] + 1, lis[j]);
            }
        }
    }

    ll la = 1;
    for(ll i = 0; i < n; i++) {
        la = max(la , lis[i]);
    }

    return la;
}

int main() {

    ll n, k;
    cin >> n >> k;
    ll arr[n] = {0};

    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    if(n == k) {
        sort(arr , arr + n);
        for(ll i = 0 ; i < n ; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return 0;
    }

    ll la = lislength(arr , n);
    vector <ll> v1, v2, v3;

    ll sublen = 1;
    for(ll start = 0 ; start < n - 1  ; start++) {
        for(ll i = 0 ; i < n ; i++) {
            if(i <= start ) {
                v1.push_back(arr[i]);
            }
            else{
                v2.push_back(arr[i]);
            }
        }

        ll v33[n] = {0};
        for(ll c = 0 ; c < v2.size() ; c++) {
            v3.push_back(v2[c]);
        }

        for(ll c = 0 ; c < v1.size() ; c++) {
            v3.push_back(v1[c]);
        }

        for(ll c = 0 ; c < n ; c++) {
            v33[c] = v3[c];
        }

        ll sublen = LongestIncreasingSubsequenceLength(v3);
        if(sublen > la) {
            for(ll z = 0 ; z < n ; z++) {
                cout << v3[z] << " ";
            }
            cout << endl;
            return 0;
        }
        v2.clear();
        v1.clear();
        v3.clear();
    }
    return 0;
}
