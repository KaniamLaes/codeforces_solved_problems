#include <bits/stdc++.h>
using namespace std;

#define asc(x) sort(x.begin(), x.end())

#define all(x) x.begin(),x.end()

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> h(2*n);
        int sum=0;
        for (int i = 0; i < 2*n; i++)
        {
            cin >> h[i];
           
        }
        int flag=1;
        asc(h);
        for(int i=n;i<2*n;i++){
            if(h[i]-h[i-n]<x){flag=-1; break;}
        }
        if(flag==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}