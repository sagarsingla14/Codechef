#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>

#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
typedef pair<long long, long long> ii;

const long long MOD = 1e9 + 7;
// ^ + shift + k = delete
// ^ + cmd + arrow = move;


int main() {
	fast_io();
	int n, m, k; cin >> n >> m >> k;


	cout << n + m + n*m - 3 << "\n";

	for(int i = 0; i < m-1; ++i) {
		cout << "L";
	}
	for(int i = 0; i < n-1; ++i) {
		cout << "U";
	}
	int row = 0;
	while(true) {
		for(int i = 0; i < m-1; ++i) {
		cout << "R";
		}
		row += 1;
		if(row == n) break;
		cout << "D";
		for(int i = 0; i < m-1; ++i) {
			cout << "L";
		}
		row += 1;
		if(row == n) break;
		cout << "D";
	}



	cout << "\n";
}
