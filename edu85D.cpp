#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n , l , r , t;
ll start = -1, endd = -1;
ll v[500001] = {0};
ll s[100010] = {0};

void findStage() {
    ll sum = 0;
    for(ll i = 1 ; i < n ; i ++) {
        sum += (2 * n - 2 * i);
        s[i] = sum;
        if(sum >= l && start == -1) {
            start = i;
        }
        if(sum >= r && endd == -1) {
            endd = i;
        }
    }
    if(r == (n * (n - 1) + 1)) {
        endd = n;
    }
}

void formPath() {
    ll index = 1;
    for(ll i = start ; i <= endd; i++) {
        if(i == endd && endd == n) {
            v[index] = 1;
        }
        else{
            ll next = i + 1;
            for(ll j = 1 ; j <= n - i ; j ++) {
                v[index] = i;
                v[index + 1] = next;
                next ++;
                index += 2;
            }
        }
    }
}

void printAns() {
    ll startIndex = l - s[start - 1];
    for(ll i = 0 ; i < (r - l + 1) ; i++) {
        cout << v[startIndex] << " ";
        startIndex ++;
    }
    cout << endl;
}


int main() {

    cin >> t;
    while(t--) {
        cin >> n >> l >> r;
        memset(v , 0 , sizeof(v));
        memset(s , 0 , sizeof(s));

        start = -1, endd = -1;
        if(l == r && r == ((n * (n - 1) + 1))) {
            cout << 1 << endl;
        }
        else{
            findStage();
            formPath();
            printAns();
        }
    }
    return 0;
}
