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
        int n;
        cin >> n;
        vector<long long> a(n);
        long long sum=0;
        long long first = -1;
        long long ct0=0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(first==-1 && a[i]!=0 ) first=i;
            if(a[i]==0 && first!=-1 && i<n-1)ct0++;
            if(i<n-1)sum+=a[i];
           
        }
       cout<<sum+ct0<<endl;
    }
}