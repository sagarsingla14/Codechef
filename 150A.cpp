#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
ll arr[100001];
unordered_set <ll> ans;
unordered_set <ll> cur;
vector <unordered_set <ll> > v(100001);
unordered_set <ll> previous;

void calcprevious(ll index) {
    previous.clear();
    previous = v[index - 1];
}

int main() {
    cin >> n;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    for(ll i = 0 ; i < n ; i++) {
        cur.clear();
        if(i == 0) {
            cur.insert(arr[i]);
        }
        else{
            calcprevious(i);
            for(auto itr : previous) {
                cur.insert(itr | arr[i]);
            }
            cur.insert(arr[i]);
        }
        v[i] = cur;
        cur.clear();
    }

    for(ll i = 0 ; i < n ; i++) {
        for(auto i : v[i]) {
            ans.insert(i);
        }
    }

    cout << ans.size() << endl;
    return 0;
}
