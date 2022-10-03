//  “Work like there is someone working 24 hours a day to take it away from you.”

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ld long double
#define db double
#define el '\n'
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
#define asc(x) sort(x.begin(),x.end())
#define des(x) sort(x.begin(),x.end(),greater<int>())
#define rep(i, n) for (int i = 0; i < n; i++)
#define rev(i, n) for (int i = n; i >= 0; i--)
#define rep_a(i, a, n) for (int i = a; i < n; i++)

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define int long long


const long long MOD = 998244353;
const long long INF = 1e9 + 10;
const long long INFLL = 1e18;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef set<int> si;
typedef set<ll> sll;

typedef map<int, int> mii;
typedef map<ll, ll> mll;

#define yes cout << "YES\n"
#define no  cout << "NO\n"

#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define SUM(v) accumulate(all(v), 0LL)
#define MIN(v) *min_element(all(v))
#define MAXX(v) *max_element(all(v))
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;


ll stringtointeger(string s){  ll num; num = stoi(s); return num;}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll pwr(ll a, ll b) { ll res = 1; while (b > 0) {if (b & 1) res = res * a ; a = a * a; b >>= 1;} return res;}

const int N=200005;

//------------------------------------------------------------------------

void solve(){
    // int n,q; cin>>n>>q;
    // vi a(n); rep(i,n) cin>>a[i];
    // int index_max=-1,max_ele=0;
    // rep(i,n){
    //     if(a[i]>max_ele) index_max=i,max_ele=a[i];
    // }
    // while(q--){
    //     int ath,k; cin>>ath>>k;
    //     ath--;
    //     if(a[ath]==max_ele){
    //         if(ath+1<=2) cout<<k<<el;
    //         else cout<<k-2<<el;
    //         return;
    //     }
    //     if(ath>index_max){
    //         cout<<0<<el; return;
    //     }
    //     if(ath<index_max){
            
    //         while()
    //     }
    // }

    // int n, q;
    // cin >> n >> q;
    // vector<int> a(n);
    // for (int i = 0; i < n; i++) {
    //   cin >> a[i];
    // }      
    // vector<int> win;
    // vector<vector<int>> qs(n);
    // int idx = 0;
    // for (int i = 1; i < n; i++) {
    //   if (a[i] > a[idx]) {
    //     idx = i;        
    //   }
    //   win.push_back(idx);
    //   qs[idx].push_back(i);
    // }
    // while (q--) {
    //   int i, k;
    //   cin >> i >> k;
    //   --i; 
    //   int wins = lower_bound(qs[i].begin(), qs[i].end(), k + 1) - qs[i].begin();
    //   if (i == idx) {
    //     wins += max((int)0, k - (n - 1));     
    //   }
    //   cout << wins << '\n';
    // }

     int n,q;
    cin>>n>>q;
    deque<pair<int,int>> dq;
    int st;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        dq.push_back({a,i});
        if(a==n)    st=i;
    }
    vector<vector<int>> p(n);
    for(int i=0;i<st;i++)
    {
        auto a1=dq.front();
        dq.pop_front();
        auto a2=dq.front();
        dq.pop_front();
        if(a1.first<a2.first)   swap(a1,a2);
        p[a1.second].push_back(i);
        dq.push_back(a2);
        dq.push_front(a1);
    }
    while(q--)
    {
        int i,k;
        cin>>i>>k;
        int ans=0;
        ans+=upper_bound(p[i-1].begin(),p[i-1].end(),min(k,st)-1)-p[i-1].begin();
        // cout<<ans<<el;
        if(i-1==st) ans+=max(1LL*0,k-st);
        cout<<ans<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

       solve();

    }

    return 0;
}