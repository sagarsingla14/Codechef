#include <iostream>
#include <algorithm>
using namespace std;
bool foo(long long a, long long b) {
	return (a > b) ? true : false;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k, e;
		long long m;
		cin >> n >> k >> e >> m;
		long long temp, arrsum[n - 1], sum, output;
		for (int i = 0; i < n - 1; i++)
		{
			sum = 0;
			for (int j = 0; j < e; j++)
			{
				cin >> temp;
				sum += temp;
			}
			arrsum[i] = sum;
		}
		sum = 0;

		for (int i = 0; i < e - 1; i++)
		{
			cin >> temp;
			sum += temp;
		}
		sort(arrsum, arrsum + n - 1, foo);
		output = arrsum[k - 1] - sum + 1;
		if(output < 0)
			cout<< 0<<'\n';
		else
		if (output < m)
			cout << output << '\n';
		else
			cout << "Impossible\n";
	}
	return 0;
}
