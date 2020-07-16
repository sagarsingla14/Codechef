#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fast_io
    ll n;
    cin >> n;
    vector <pair <ll , ll> > arr[n];
    vector <pair <ll , ll> > dp[n];
    vector <pair <ll , ll> > dp5[n];

    vector <char> path[n];
    vector <char> path5[n];

    path[0].push_back('-');
    path5[0].push_back('-');

    ll zero = 0;
    ll zx , zy;

    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < n ; j++) {
            ll x;
            cin >> x;

            ll two = 0 , five = 0;
            if(x == 0) {
                zero = 1;
                arr[i].push_back({-1 , -1});
                zx = i;
                zy = j;
            }
            else {
                while(x % 2 == 0) {
                    two ++;
                    x /= 2;
                }
                while(x % 5 == 0) {
                    five ++;
                    x /= 5;
                }
                arr[i].push_back({two , five});
            }
        }
    }

    string ansZero = "";

    if(zero) {
        for(ll i = 0 ; i < zx ; i++) {
            ansZero += 'D';
        }
        for(ll i = 0 ; i < zy ; i++) {
            ansZero += 'R';
        }
        for(ll i = zx ; i < n - 1; i++) {
            ansZero += 'D';
        }
        for(ll i = zy ; i < n - 1; i++) {
            ansZero += 'R';
        }
    }
    if(arr[0][0].first == -1 && arr[0][0].second == -1) {
        dp[0].push_back({0 , 0});
    }
    else{
        dp[0].push_back(arr[0][0]);
    }

    for(ll i = 1 ; i < n ; i++) {
        ll x = 0 , y = 0;
        if(arr[0][i].first == -1 && arr[0][i].second == -1) {
            dp[0].push_back({x , y});
        }
        else {
            x = dp[0][i - 1].first + arr[0][i].first;
            y = dp[0][i - 1].second + arr[0][i].second;
            dp[0].push_back({x , y});
        }
        path[0].push_back('R');
    }

    for(ll i = 1 ; i < n ; i++) {
        ll x = 0 , y = 0;
        if(arr[i][0].first == -1 && arr[i][0].second == -1) {
            dp[i].push_back({x , y});
        }
        else {
            x = dp[i - 1][0].first + arr[i][0].first;
            y = dp[i - 1][0].second + arr[i][0].second;
            dp[i].push_back({x , y});
        }
        path[i].push_back('D');
    }

    if(arr[0][0].first == -1 && arr[0][0].second == -1) {
        dp5[0].push_back({0 , 0});
    }
    else{
        dp5[0].push_back(arr[0][0]);
    }

    for(ll i = 1 ; i < n ; i++) {
        ll x = 0 , y = 0;
        if(arr[0][i].first == -1 && arr[0][i].second == -1) {
            dp5[0].push_back({x , y});
        }
        else {
            x = dp5[0][i - 1].first + arr[0][i].first;
            y = dp5[0][i - 1].second + arr[0][i].second;
            dp5[0].push_back({x , y});
        }
        path5[0].push_back('R');
    }

    for(ll i = 1 ; i < n ; i++) {
        ll x = 0 , y = 0;
        if(arr[i][0].first == -1 && arr[i][0].second == -1) {
            dp5[i].push_back({x , y});
        }
        else {
            x = dp5[i - 1][0].first + arr[i][0].first;
            y = dp5[i - 1][0].second + arr[i][0].second;
            dp5[i].push_back({x , y});
        }
        path5[i].push_back('D');
    }

    for(ll i = 1 ; i < n ; i++) {
        for(ll j = 1 ; j < n ; j++) {
            ll x = 0 , y = 0;
            if(arr[i][j].first == -1 && arr[i][j].second == -1) {
                dp[i].push_back({x , y});
                path[i].push_back('D');
            }
            else{
                ll mnL = dp[i][j - 1].first;
                ll mnU = dp[i - 1][j].first;

                if(mnL >= mnU) {
                    x = arr[i][j].first + dp[i - 1][j].first;
                    y = arr[i][j].second + dp[i - 1][j].second;
                    dp[i].push_back({x , y});
                    path[i].push_back('D');
                }
                else if(mnL < mnU) {
                    x = arr[i][j].first + dp[i][j - 1].first;
                    y = arr[i][j].second + dp[i][j - 1].second;
                    dp[i].push_back({x , y});
                    path[i].push_back('R');
                }
            }
        }
    }

    for(ll i = 1 ; i < n ; i++) {
        for(ll j = 1 ; j < n ; j++) {
            ll x = 0 , y = 0;
            if(arr[i][j].first == -1 && arr[i][j].second == -1) {
                dp5[i].push_back({x , y});
                path5[i].push_back('D');
            }
            else{
                ll mnL = dp5[i][j - 1].second;
                ll mnU = dp5[i - 1][j].second;

                if(mnL >= mnU) {
                    x = arr[i][j].first + dp5[i - 1][j].first;
                    y = arr[i][j].second + dp5[i - 1][j].second;
                    dp5[i].push_back({x , y});
                    path5[i].push_back('D');
                }
                else if(mnL < mnU) {
                    x = arr[i][j].first + dp5[i][j - 1].first;
                    y = arr[i][j].second + dp5[i][j - 1].second;
                    dp5[i].push_back({x , y});
                    path5[i].push_back('R');
                }
            }
        }
    }

    ll tMin = min(dp[n - 1][n - 1].first , dp[n - 1][n - 1].second);
    ll FMin = min(dp5[n - 1][n - 1].first , dp5[n - 1][n - 1].second);

    ll PosAns = min(tMin , FMin);

    if(zero) {
        if(PosAns == 0) {
            if(PosAns == tMin) {
                string anst = "";
                ll i = n - 1 , j = n - 1;
                while (path[i][j] != '-') {
                    if(path[i][j] == 'R') {
                        anst += 'R';
                        j --;
                    }
                    else if(path[i][j] == 'D') {
                        anst += 'D';
                        i --;
                    }
                }
                reverse(anst.begin() , anst.end());
                cout << tMin << endl << anst << endl;
            }
            else if(PosAns == FMin){
                string ansf = "";
                ll i = n - 1 , j = n - 1;
                while (path5[i][j] != '-') {
                    if(path5[i][j] == 'R') {
                        ansf += 'R';
                        j --;
                    }
                    else if(path5[i][j] == 'D') {
                        ansf += 'D';
                        i --;
                    }
                }
                reverse(ansf.begin() , ansf.end());
                cout << FMin << endl << ansf << endl;
            }
        }
        else{
            cout << 1 << endl << ansZero << endl;
        }
    }
    else{
        if(PosAns == tMin) {
            string anst = "";
            ll i = n - 1 , j = n - 1;
            while (path[i][j] != '-') {
                if(path[i][j] == 'R') {
                    anst += 'R';
                    j --;
                }
                else if(path[i][j] == 'D') {
                    anst += 'D';
                    i --;
                }
            }
            reverse(anst.begin() , anst.end());
            cout << tMin << endl << anst << endl;
        }
        else if(PosAns == FMin){
            string ansf = "";
            ll i = n - 1 , j = n - 1;
            while (path5[i][j] != '-') {
                if(path5[i][j] == 'R') {
                    ansf += 'R';
                    j --;
                }
                else if(path5[i][j] == 'D') {
                    ansf += 'D';
                    i --;
                }
            }
            reverse(ansf.begin() , ansf.end());
            cout << FMin << endl << ansf << endl;
        }
    }
    return 0;
}
