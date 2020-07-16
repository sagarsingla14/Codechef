#include <bits/stdc++.h>
using namespace std;

int spf[5000001];

void sieve() {
    for(int i = 2 ; i <= 5000000 ; i++) {
        spf[i] = i;
    }

    for(long long i = 2 ; i * i <= 5000000 ; i++) {
        if(spf[i] == i) {
            for(long long j = i * i ; j <= 5000000 ; j += i) {
                spf[j] = i;
            }
        }
    }

    spf[0] = 0;
    spf[1] = 0;
    for(long long i = 2 ; i <= 5000000 ; i++) {
        spf[i] = spf[i / spf[i]] + 1;
    }
    for(int i = 3 ; i <= 5000000 ; i++) {
        spf[i] += spf[i - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;
    cin >> t;
    while(t--) {
        long long a , b;
        cin >> a >> b;
        long long ans = spf[a] - spf[b];
        cout << ans << endl;
    }

    return 0;
}
