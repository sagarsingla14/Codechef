#include<bits/stdc++.h>
using namespace std;
#define Int long long
set<Int> S;bool Hash[26];
int main(){

	string s,a;Int i,j,k,cnt,tmp;
	cin>>s>>a>>k;
	for(i=0;i<26;i++){
		Hash[i] = a[i] - '0';
	}
	for(i=0;s[i]!='\0';i++){
		cnt = 0;tmp=0;
		for(j=i;s[j]!='\0';j++){
			if(!Hash[s[j]-'a'])
				cnt++;
			if(cnt>k)break;
			cout << i << " " << j << endl;
			tmp *= 101LL;
			tmp += s[j];

			cout <<"temp -> " << tmp << endl;
			S.insert(tmp);
		}
	}

	for(auto i : S) {
		cout << i << " ";
	}
	cout << endl;

	printf("%d\n",S.size() );
	return 0;
}
