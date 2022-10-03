#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    stack<char> s;
    string ans="";
    int a=0;
    for(int i=0;i<s1.size();i++)
    {
        ans+=s1[i];
        s.push(s1[i]);
        while(!s.empty() && s.top()==s2[a])
        {
            ans+='*';
            s.pop();
            a++;
            if(a==s2.size())
            break;
        }
        // if(a==s2.size())
        //     break;
    }
    if(a==s2.size())
    {
        cout<<"Yes"<<endl;
        cout<<ans<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
}

signed main(){
    FastIO;
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}