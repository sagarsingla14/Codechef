#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

struct Node {
    ll w , h , index;
};

bool comp(Node *a , Node *b) {
    return a -> w < b -> w;
}

int main() {
    ll n , width , height;
    cin >> n >> width >> height;

    vector <Node*> v;
    for(ll i = 0 ; i < n ; i++) {
        ll ww , hh;
        cin >> ww >> hh;
        if(ww > width && hh > height) {
            Node *cur = new Node();
            cur -> w = ww;
            cur -> h = hh;
            cur -> index = i + 1;
            v.push_back(cur);
        }
    }
    ll sze = v.size();
    if(sze == 0) {
        cout << 0 << endl;
    }
    else{
        sort(v.begin() , v.end() , comp);

        ll dp[sze] = {0};
        ll from[sze] = {0};
        for(ll i = 0 ; i < sze ; i++) {
            dp[i] = 1;
            from[i] = i;
        }
        for(ll i = 0 ; i < sze ; i++) {
            for(ll j = i ; j < sze ; j ++) {
                if((v[j] -> w > v[i] -> w) && (v[j] -> h > v[i] -> h)) {
                    if(dp[j] < dp[i] + 1) {
                        from[j] = i;
                        dp[j] = dp[i] + 1;
                    }
                }
            }
        }

        ll mx = -1;
        ll index = 0;
        ll cnt = 0;
        for(auto i : dp) {
            if(i > mx) {
                mx = i;
                index = cnt;
            }
            cnt ++;
        }
        vector <ll> resPos;
        while(from[index] != index) {
            resPos.push_back(index);
            index = from[index];
        }
        resPos.push_back(index);
        vector <ll> result;
        for(auto i : resPos) {
            result.push_back(v[i] -> index);
        }
        cout << result.size() << endl;
        for(ll i = result.size() - 1; i >= 0 ; i--) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
