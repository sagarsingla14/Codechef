// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n;
int dp[10005][10][2];

long long getAns(int id, int val, int grt) {

	if(id == n-1) {
		return 1;
	}
	if(dp[id][val][grt] != -1) return dp[id][val][grt];

	long long cur = 0;
	if(grt) {
		// next no is less than me
		for(int j = val - 1; j >= 0; j--) {
			cur += getAns(id + 1, j, 1 - grt);
			cur %= MOD;
		}
	} else {
		// next is grt than me
		for(int j = val + 1; j < 10; ++j) {
			cur += getAns(id + 1, j, 1 - grt);
			cur %= MOD;
		}
	}
	dp[id][val][grt] = cur;
	return cur;
}


string getNum(char *num) {
	string s = "";
	for(int i = 0; num[i]; ++i) {
		s += num[i];
	}
	return s;
}




int main() {

	char str[10005]; cin >> str;
	n = strlen(str);
	if(n == 1) {
		int num = str[0] - '0';
		num += 1;
		cout << num << "\n";
		return 0;
	}
	memset(dp, -1, sizeof dp);

	long long ans = 0;
	for(int j = 0; j < n-1; ++j) {
		for(int i = 1; i < 10; ++i) {
			getAns(j, i, 0);
			getAns(j, i, 1);
			if(j > 0) {
				ans += dp[j][i][0];
				ans += dp[j][i][1];
				ans %= MOD;
			}
		}
	}
	for(int i = 1; i < str[0]-'0'; ++i) {
		ans += getAns(0, i, 0);
		ans += getAns(0, i, 1);
	}
	int prev = str[0] - '0';
	bool grt = 0;

	for(int i = 1; i <= n-1; ++i) {
		for(int j = 0; j < str[i] - '0'; ++j) {
			if(i > 1) {
				if(grt) {
					if(j < prev) {
						ans += getAns(i, j, 0);
					}
				} else {
					if(j > prev) {
						ans += getAns(i, j, 1);
					}
				}

				ans %= MOD;
			}
			if(prev > j) {
				ans += getAns(i, j, 0);
			} else if(prev < j) {
				ans += getAns(i, j, 1);
			}
			ans %= MOD;
		}
		if(i == 1) {
			if(str[i] > str[i-1]) {
				grt = 1;
			}
		}
		if(i > 1) {
			if(grt) {
				if(str[i] >= str[i-1]) {
					break;
				}
			} else {
				if(str[i] <= str[i-1]) {
					break;
				}
			}
		}
		prev = str[i] - '0';
		if(i > 1) {
			grt = 1 - grt;
		}

	}

	string s = getNum(str);
	int arr[s.length() - 1];
	for(int i = 1; i < s.length(); ++i) {
		if(s[i] > s[i-1]) {
			arr[i-1] = 0;
		} else if(s[i] < s[i-1]){
			arr[i-1] = 1;
		} else {
			arr[i-1] = -1;
		}
	}
	bool yes = true;
	for(int i = 1; i < s.length() - 1; ++i) {
		if(arr[i] == -1) {
			yes = false;
			break;
		}
		if(arr[i] ^ arr[i-1]) {
			continue;
		}
		yes = false;
	}
	if(arr[0] == -1) yes = false;
	if(yes) ans += 1;



	ans += 10;


	ans %= MOD;
	cout << ans << "\n";

}
