#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define K 25

int st[MAX][K];

int BinSearch(int n , int dist[] , int a[] , int c)  {
    int l = 1 , r = n;
    int val = 0;

    while(l <= r) {
        int mid = (l + r) >> 1;

        int ok = 0;
        for(int i = 1 ; i <= n - mid + 1 ; i++) {

            int sum = dist[i + mid - 1] - dist[i - 1];
            int j = log2(r - l + 1);
            int mx = min(st[l][j] , st[r - (1ll << j) + 1][j]);

            if(mx + mid * sum <= c) {
                ok = 1;
                break;
            }
        }

        if(!ok) {
            r = mid - 1;
        }
        else {
            val = mid;
            l = mid + 1;
        }
    }
    return val;
}

void calcSparseTable(int b[] , int n) {
    for(int j = 1 ; j <= K ; j ++) {
        for(int i = 0 ; (i + (1ll << j)) <= n ; i++) {
            st[i][j] = max(st[i][j - 1] , st[i + (1ll << (j - 1))][j - 1]);
        }
    }
}

void FillDp(int a[] , int dist[] , int n) {
    for(int i = 1 ; i <= n ; i++) {
        dist[i] = a[i] + dist[i - 1];
    }
    return ;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n , c;
        cin >> n >> c;


        memset(st , 0 , sizeof(st));
        int a[n + 1] = {0};
        int b[n + 1] = {0};
        int dist[n + 1] = {0};

        for(int i = 1 ; i <= n ; i++) {
            cin >> a[i];
        }
        for(int i = 0 ; i < n ; i++) {
            cin >> b[i];
            st[i][0] = b[i];
        }

        FillDp(a , dist , n);
        calcSparseTable(b , n);

        cout << BinSearch(n , dist , a , c) << endl;
    }
    return 0;
}
