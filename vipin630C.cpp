#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
#include <cstring>

#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
typedef pair<int, int> ii;

const long long MOD = 1e9 + 7;

int main() {
	fast_io();
	int t; cin >> t;

	while(t--) {
		int n, k; cin >> n >> k;
		char str[n+1]; cin >> str;

		int mat[k][26];

		memset(mat, 0, sizeof mat);
		for(int i = 0; i < n; ++i) {
			mat[i%k][str[i] - 'a'] += 1;
		}

		int m = n / k;

		int cnt = 0;
		for(int pos = 0; pos < k/2; ++pos) {
			int hs = n;
			for(int vr = 0; vr < 26; ++vr) {
				int a = m - mat[pos][vr];
				int b = m - mat[k - pos - 1][vr];
				hs = min(hs, a + b);
			}
			cnt += hs;
		}
		cout << " cnt till - > " << cnt << endl;

		if(k%2) {
			int hs = n;
			for(int vr = 0; vr < 26; ++vr) {
				int a = m - mat[k/2][vr];
				hs = min(hs, a);
			}
			cnt += hs;
		}

		cout << cnt << "\n";

	}
}
//
// 4
// 6 2
// abaaba
// 6 3
// abaaba
// 36 9
// hippopotomonstrosesquippedaliophobia
// 21 7
// wudixiaoxingxingheclp
