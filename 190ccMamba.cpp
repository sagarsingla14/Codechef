#include <bits/stdc++.h>

using namespace std;

int a, b, x, y;
string s;
vector<pair<int , int>> all;

int main()
{
	ios::sync_with_stdio(0);
	cin >> a >> b >> s;
	all.push_back({ 0 , 0 });
	for (auto i : s)
	{
		if (i == 'U')
			y++;
		if (i == 'D')
			y--;
		if (i == 'R')
			x++;
		if (i == 'L')
			x--;
		all.push_back({ x , y });
	}
	for (auto i : all)
	{
		int xd = abs(a - i.first);
		int yd = abs(b - i.second);
		if (!xd && !yd)
			return cout << "Yes" << endl, 0;
		int go = 0;
		if (!x && !y)
			continue;
		if (x)
			go = xd / x;
		if (y)
			go = yd / y;
		go = abs(go);
		if ((i.first + go * x) == a && (i.second + go * y) == b)
			return cout << "Yes" << endl, 0;
	}
	cout << "No" << endl;
	return 0;
}
