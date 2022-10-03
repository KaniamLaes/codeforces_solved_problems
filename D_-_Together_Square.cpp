// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//   int n;
//   cin>>n;
//   vector<bool> sq(n+1,false);
//   for(int i=1;i*i<=n;i++) sq[i*i]=true;
//   vector<vector<int>> d(n+1);
//   for(int i=1;i<=n;i++){
//     for(int j=i;j<=n;j+=i) d[j].push_back(i);
//   }
//   vector<int> cnt(n+1);
//   for(int i=1;i<=n;i++){
//     int f=0;
//     for(int j=0;j<d[i].size();j++) if(sq[d[i][j]]) f=d[i][j];
//     cnt[i/f]++;
//   }
//   int ans=0;
//   for(int i=1;i<=n;i++) ans+=cnt[i]*cnt[i];
//   cout<<ans<<endl;
  


// }


// https://atcoder.jp/contests/abc254/editorial/4076
// editorial




#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N=500;

int n;
int ex[N];
LL res;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<N;i++) ex[i]=i*i;
	for(int i=1;i<=n;i++)
	{
		int t=i,ps=1;	
		for(int j=2;j<=i/j;j++)
		{
			int cnt=0;
			while(t%j==0)
			{
				t/=j;
				cnt++;
			}
			if(cnt&1) ps*=j;
		}
		// if(t!=1)
     ps*=t; 
		for(int j=1;(LL)ex[j]*ps<=n;j++)
			res++;
	}	
	printf("%d\n",res);
	
	return 0;
} 