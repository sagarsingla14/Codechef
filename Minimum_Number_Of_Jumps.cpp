#include <bits/stdc++.h>
using namespace std;

int n, mxReach = 0, ans = 0, step = 0 , ok = 0;

void solve(int arr[]) {

    ok = 0 , step = arr[0] , ans = 1 , mxReach = arr[0];
    for(int i = 1 ; i < n ; i++) {
        if(i == n - 1) {
            ok = 1;
            break;
        }

        mxReach = max(mxReach , i + arr[i]);
        step --;

        if(step < 0) {
            ok = 0;
            break;
        }

        if(!step) {
            ans ++;
            if(i >= mxReach) {
                ok = 0;
                break;
            }
            step = mxReach - i;
        }
    }

    if(ok) {
        cout << ans << endl;
    }
    else {
        cout << -1 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        int arr[n] = {0};
        for(int i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }

        if(n == 1) {
            cout << 0 << endl;
        }
        else{
            solve(arr);
        }
    }
    return 0;
}
