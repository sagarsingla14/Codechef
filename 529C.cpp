n#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007

priority_queue <ll> pq;

ll setBits(ll n) {
    ll setBit = 0;
    ll cnt = 0;
    while(n) {
        if((n & 1)) {
            setBit ++;
            ll val = 1ll << cnt;
            pq.emplace(val);
            // cout <<"pushed " << val << endl;
        }
        n >>= 1ll;
        cnt ++;
    }
    return setBit;
}

int main() {
    ll n , k;
    cin >> n >> k;
    if(k > n || k < setBits(n)) {
        cout << "NO" << endl;
    }
    else {
        while(pq.size() < k && !pq.empty()) {
            ll val = pq.top();
            pq.pop();
            if(val & 1) {
                pq.emplace(1);
            }
            pq.emplace(val / 2);
            pq.emplace(val / 2);
        }
        if(pq.size() != k) {
            cout << "NO" << endl;
        }
        else{
            vector <ll> ans;
            ll ok = 1;
            while(!pq.empty()) {
                ll val = pq.top();
                ans.push_back(val);
                if(val != 1 && (val % 2)) {
                    ok = 0;
                }
                pq.pop();
            }

            if(!ok) {
                cout << "NO" << endl;
            }
            else{
                cout << "YES" << endl;
                for(auto i : ans) {
                    cout << i << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
    return 0;
}
