#include<bits/stdc++.h>
#define PRE ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
void solve()
{
    int n;
    cin>>n;
    if(n>19)
    {
        cout<<"NO\n";
        return;
    }
    else
    {
        cout<<"YES\n";
        for(int i=1,j=1;i<=n;i++)
        {
            cout<<j<<' ';
            j*=3;
        }
        cout<<'\n';
    }
}
main()
{
    PRE;
    int T=1;
    cin>>T;
    while(T--)solve();
}
