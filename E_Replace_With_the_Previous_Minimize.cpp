#include<bits/stdc++.h>
using namespace std;
int t,n,k;
string s;
int main(){	
	scanf("%d",&t);
	while(t--){
		// scanf("%d %d",&n,&k);
		// cin>>s;
		// map<char,int>mp;
		// for(int i=0;i<n;i++){
		// 	while(s[i]>'a'){
		// 		if(mp[s[i]]) s[i]--;
		// 		else if(k) mp[s[i]]=1,k--,s[i]--;
		// 		else break;
		// 	}
		// }
		// cout<<s<<endl;
		cin>>n>>k;
		cin>>s;
		map<char,int>mp;
		for(int i=0;i<n;i++){
			while(s[i]>'a'){
				if(mp[s[i]]) s[i]--;
				else if(k) mp[s[i]]=1,s[i]--,k--;
				else break;
			}
		}
		cout<<s<<endl;
	}
}