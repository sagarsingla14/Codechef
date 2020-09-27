#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

double findMedianSortedArrays(vector<int>& x , vector<int>& y) {
    if(x.size() > y.size()) {
        vector <int> temp = x;
        x = y;
        y = temp;
    }

    int l = 0 , r = x.size();
    int half = (x.size() + y.size() + 1) >> 1;
    double ans = 0;

    for(auto i : x) {
        cout << i << " ";
    }
    cout << endl;

    for(auto i : y) {
        cout << i << " ";
    }
    cout << endl;

    while(l <= r) {

        cout << "l r " << l << " " << r << endl;
        int lx = (l + r) >> 1;
        int rx = half - lx;

        cout << lx << " " << rx << endl;
        int mxX = (lx == 0) ? INT_MIN : x[lx - 1];
        int mxY = (rx == 0) ? INT_MIN : y[rx - 1];

        int mnX = lx == (x.size()) ? INT_MAX : x[lx];
        int mnY = rx == (y.size()) ? INT_MAX : y[rx];

        if(mxX <= mnY && mxY <= mnX) {
            if((x.size() + y.size()) % 2) {
                ans = max(mxX , mxY);
            }
            else{
                ans = (max(mxX , mxY) + min(mnX , mnY)) / 2.0;
            }
            break;
        }
        else if(mxX > mnY) {
            r = lx - 1;
        }
        else{
            l = lx + 1;
        }
    }
    cout << "ans ";
    return ans;
}

int main() {
    int n , m;
    cin >> n >> m;

    vector <int> a , b;
    for(int i = 0 ; i < n ; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    for(int i = 0 ; i < m ; i++) {
        int x; cin >> x;
        b.push_back(x);
    }

    cout << findMedianSortedArrays(a , b) << endl;
    return 0;
}
