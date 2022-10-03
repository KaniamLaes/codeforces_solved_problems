#include <bits/stdc++.h>
#define ll long long
#define pp push_back
#define ff first
#define ss second
#define SPEED ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

ll x[1000001],y[1000001],z,h,xx[1000001],yy[1000001],xxx,yyy,zz,aa,bb,vis,mod=1e9+7,inf=1e18;
ll i,j,ii,jj,q,n,m,mm,a,b,c,g,d[1000001],k,r1,l1,n1,n2,n3;
vector <pair <ll,ll> > v,vv;
pair <ll,ll> p,p1;
queue <ll> qq;
map <ll,ll> mp,mpp,mppp;
multiset <ll> e,ee;
set <pair <ll,ll> > :: iterator it,itt,it1,itt1;
string s,t,s2,s1,tt;
char cc;

int main()
{
    SPEED;
    int T=1;
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(i=0;i<n;i++)
        {
            cin >> x[i];
            y[i]=x[i];
        }
        if(n==1)
        {
            cout << -1 << endl;
            continue;
        }
        sort(y,y+n);
        for(i=0;i<n-1;i++)
        {
            if(x[i]==y[i])
                swap(y[i],y[i+1]);
        }
        if(x[i]==y[i])
            swap(y[i],y[i-1]);
        for(i=0;i<n;i++)
            cout << y[i] << ' ';
        cout << endl;
    }
    return 0;
}
/*

*/
