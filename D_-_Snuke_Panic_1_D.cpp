// //  “Work like there is someone working 24 hours a day to take it away from you.”

// #include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using namespace std;

// #define ll long long
// #define ld long double
// #define db double
// #define el '\n'
// #define ld long double
// #define pb push_back
// #define all(x) x.begin(),x.end()
// #define asc(x) sort(x.begin(),x.end())
// #define des(x) sort(x.begin(),x.end(),greater<int>())
// #define rep(i, n) for (int i = 0; i < n; i++)
// #define rev(i, n) for (int i = n; i >= 0; i--)
// #define rep_a(i, a, n) for (int i = a; i < n; i++)

// typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// #define int long long


// const long long MOD = 998244353;
// const long long INF = 1e9 + 10;
// const long long INFLL = 1e18;

// typedef pair<int, int> pi;
// typedef pair<ll,ll> pl;
// typedef pair<ld,ld> pd;

// typedef set<int> si;
// typedef set<ll> sll;

// typedef map<int, int> mii;
// typedef map<ll, ll> mll;

// #define yes cout << "YES\n"
// #define no  cout << "NO\n"

// #define popcount(x) __builtin_popcount(x)
// #define popcountll(x) __builtin_popcountll(x)
// #define fi first
// #define se second
// #define SUM(v) accumulate(all(v), 0LL)
// #define MIN(v) *min_element(all(v))
// #define MAXX(v) *max_element(all(v))
 
// typedef vector<int> vi;
// typedef vector<ld> vd;
// typedef vector<ll> vl;
// typedef vector<pi> vpi;
// typedef vector<pl> vpl;


// ll stringtointeger(string s){  ll num; num = stoi(s); return num;}
// ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
// ll pwr(ll a, ll b) { ll res = 1; while (b > 0) {if (b & 1) res = res * a ; a = a * a; b >>= 1;} return res;}

// const int N=200005;

// //------------------------------------------------------------------------
// map<array<int,2>,int>sum;
// int maxi=0;
// int dp[5][100005];

// int rec(int x,int t){
//     if(x<0 or x==5 or t>maxi){
//         return 0;
//     }
//     if(dp[x][t]!=-1) return dp[x][t];
     
//     dp[x][t]=sum[{x,t}]+max({rec(x-1,t+1),rec(x,t+1),rec(x+1,t+1)});
//     return dp[x][t];

// }

// /**
//  *  
//  * from any coordinate,time (say x,t) we can go either left or right or stay in the same place after each second 
//  * thus using recursion helps to determine all the possible paths 
//  * 
//  */

// void solve(){
//     memset(dp,-1,sizeof(dp));
//     int n; cin>>n;
//     for(int i=0;i<n;i++){
//         int t,x,a;
//         cin>>t>>x>>a;
//         maxi=max(maxi,t);
//         sum[{x,t}]=a;
//     }
//     cout<<rec(0,0)<<el;

// }

// int32_t main()
// {
//     ios_base::sync_with_stdio(0); cin.tie(0);
//     // int t;
//     // cin >> t;
//     // while (t--)
//     // {

//        solve();

//     // }

//     return 0;
// }



#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> t(n), x(n), a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> t[i] >> x[i] >> a[i];

    constexpr int inf = 1e9;
    std::vector<i64> dp(n, -inf);

    if (t[0] >= x[0])
        dp[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        if (t[i] >= x[i])
            dp[i] = a[i];

        for (int j = 1; j <= 10 and i - j >= 0; ++j)
        {
            int need = std::abs(x[i] - x[i - j]);
            int can = t[i] - t[i - j];

            if (need > can)
                continue;
            dp[i] = std::max(dp[i], dp[i - j] + a[i]);
        }
    }

    
    i64 ans = 0;
    for (int i = 0; i < n; i++)
        ans = std::max<i64>(ans, dp[i]);

    std::cout << ans << "\n";

    return 0;
}

/**
 *  let dp_i = maximum size of snukes you can catch if you want to catch snuke-i (it is possible that this value is 0)  but when? 
suppose first snuke appears at time-1 at position-2 then you will never be able to catch it, so keep it's value -inf
Now for each snuke-i you can check the maximum value of dp[i - j] + size_of_snuke[i] if |x[i - j] - x[i]| is less than equal to t[i] - t[i - j]
,  where j < i.. 
 * 

 the thing is, if I skip i - 10 to i - 1 then I will be able to catch i for sure
since t[i] < t[i + 1]
so atleast one second difference will be there
 */