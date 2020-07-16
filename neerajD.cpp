#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main()
{
	fast_io();
    int t;
    cin >> t;
    while(t--)
    {
    	int n;
    	cin >> n;
    	vector<int> vec;
    	set<int> st;
    	for (int i = 0; i < n; ++i)
    	{
    	    int a;
    	    cin >> a;
    	    vec.push_back(a);
    	    st.insert(a);
    	}

    	if(st.size() == 1) {
    		cout << "1\n";
    		for (int i = 0; i < n; ++i)
    		{
    		    cout << "1" << " ";
    		}
    		cout << "\n";
    		continue;
    	}

    	if(vec[0] == vec[n - 1] ) {
    		cout << "2\n";
    		int ans[n];
    		ans[0] = 1;
    		for (int i = 1; i < n; ++i)
    		{
    		    if(vec[i] == vec[i - 1] ) {
    		    	ans[i] = 1;
    		    	continue;
    		    }
    		    if(ans[i - 1] == 1) {
    		    	ans[i] = 2;
    		    }
    		    else {
    		    	ans[i] = 1;
    		    }
    		}

    		for (int i = 0; i < n; ++i)
    		{
    		    cout << ans[i] << " ";
    		}
    		cout << "\n";
    		continue;

    	}

    	int ans[n];

    	ans[0] = 1;
    	ans[n - 1] = 2;

    	int i = 1;
    	int ind = -1;
    	for (int i = 1; i < n - 1; ++i)
    	{
    	    if(vec[i] == vec[i - 1]) {

    	    	if(ind == -1)
    	    	ind = i;
    	    	ans[i] = 1;

    	    }

    	    if(ans[i - 1] == 1) {
    	    	ans[i] = 2;
    	    }
    	    else
    	    {
    	    	ans[i] = 1;
    	    }

    	}



    	bool fg = 0;

    	if(vec[n - 2] != vec[n - 1] && ans[n - 1] == ans[n - 2] ) {
    		if(ind != -1)
    		{
    			cout << "2\n";
    			for (int i = ind; i < n - 1; ++i)
    			{
    			    if(ans[i] == 1) ans[i] = 2;
    			    else ans[i] = 1;
    			}
    			for (int i = 0; i < n; ++i)
    			{
    			    cout << ans[i] << " ";
    			}
    			cout << "\n";
    		}

    		else
    		{

    			ans[n - 1 ] = 3;
    			cout << "3\n";
    			for (int i = 0; i < n; ++i)
    			{
    			    	cout << ans[i] << " ";
    			}

    			cout << "\n";
    		}
    		continue;
    	}

    	cout << "2\n";

    	for (int i = 0; i < n; ++i)
    	{
    	    cout << ans[i] << " ";
    	}
    	cout << "\n";


    }
    return 0;
}
//
// 1 2 1 2 3 1 2
// 1 2 1 2 1 2 2

// g++ -std=c++11
