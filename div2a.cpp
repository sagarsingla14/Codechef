#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		string k;
		int count=0;
		for(int i=0;i<n;i++){
			if(count==2){
				break;
			}
			else{
				if(int(s[i]-'0')%2==1){
					count++;
					k=k+s[i];
				}
			}
		}
		if(count==2){
			cout<<k;
		}
		else{
			cout<<"-1";
		}
        int l = s.length();
        for(int i = 0  ; i < l ; i++) {
            s[i] = '-';
        }
		cout<<endl;
	}
}
