#include <bits/stdc++.h>
using namespace std;
#define ll int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll ok = 0;
vector <pair <ll , ll>> v;
vector <ll> ans;

void merge(ll l , ll mid , ll r) {
    vector <pair <ll , ll>> left , right;

    for(ll i = l ; i <= mid;  i++) {
        left.push_back(v[i]);
    }
    for(ll i = mid + 1 ; i <= r ; i++) {
        right.push_back(v[i]);
    }

    ll i = 0 , j = 0 , k = l;
    while(i < left.size() && j < right.size()) {
        if(left[i].first > right[j].first) {
            v[k ++] = right[j ++];
        }
        else {
            ans[left[i].second] += j;
            v[k ++] = left[i ++];
        }
    }

    while(i < left.size()) {
        ans[left[i].second] += j;
        v[k ++] = left[i ++];
    }
    while(j < right.size()) {
        v[k ++] = right[j ++];
    }
}

void mergeSort(ll l , ll r) {
    if(l < r) {
        ll mid = (l + r) >> 1;
        mergeSort(l , mid);
        mergeSort(mid + 1 , r);
        merge(l , mid , r);
    }
}

void solve() {
    
}

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        ok = 0;

        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }

        solve(arr , n , 0 , 0);
        solve(arr , n , 0 , 1);

        if(ok) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
