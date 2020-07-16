#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int arr[n] = {0};
        for(int i = 0; i < n ; i++) {
            cin >> arr[i];
        }

        int index = 0;
        for(int i = 31 ; i >= 0 ; i--) {
            int mx = -1 , mxIndex = -1;
            for(int j = index ; j < n ; j++) {
                int bit = (arr[j] >> i) & 1;
                if(bit) {
                    if(arr[j] > mx) {
                        mxIndex = j;
                        mx = arr[j];
                    }
                }
            }

            if(mx == -1) {
                continue;
            }
            else {
                swap(arr[index] , arr[mxIndex]);
                for(int j = 0 ; j < n ; j++) {
                    if(j != index) {
                        int bit = (arr[j] >> i) & 1;
                        if(bit) {
                            arr[j] ^= mx;
                        }
                    }
                }
            }
            index ++;
        }

        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            ans ^= arr[i];
        }

        cout << ans << endl;
    }
    return 0;
}
