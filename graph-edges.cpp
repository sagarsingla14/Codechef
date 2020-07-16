#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		std::vector<int> v(n+1,0);
		vector<vector<int> > ans(n+1);
		for (int i = 0; i < m; ++i)
		{
			int x,y;
			cin>>x>>y;
			v[x]++;
			v[y]++;
			ans[x].push_back(y);
			ans[y].push_back(x);
		}

		vector<int> sol(n+1);


		if(m%2==0){
			cout<<1<<endl;
			for (int i = 0; i < n; ++i)
			{
				cout<<1<<" ";
			}
			cout<<endl;
		}


		else {
			int found = false;
			for (int i = 1; i <= n; ++i)
			{
				if(found == false && v[i]%2 != 0){
					found = true;
					sol[i] = 2;
				}
				else{
					sol[i] = 1;
				}
			}

			if(found == true){
				cout<<2<<endl;
				for (int i = 1; i <= n; ++i)
				{
					cout<<sol[i]<<" ";
				}
				cout<<endl;
			}
			else{
				cout<<3<<endl;
				for (int i = 1; i <= n; ++i)
				{
					if(v[i] == 2 && v[ans[i][0]] == 2 && v[ans[i][1]] == 2 ){
						if((ans[ans[i][0]][0] == ans[i][1] || ans[ans[i][0]][1] == ans[i][1]) ){
							sol[i] = 1;
							sol[ans[i][0]] = 2;
							sol[ans[i][1]] = 3;
						}
						break;
					}
				}


				for (int i = 1; i <= n; ++i)
				{
					cout<<sol[i]<<" ";
				}
				cout<<endl;
			}

		}

	}
}
