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


#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
//-------------------------------------------------------------------------

//------------------------------------------------------------------------
ll stringtointeger(string s){  ll num; num = stoi(s); return num;}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll pwr(ll a, ll b) { ll res = 1; while (b > 0) {if (b & 1) res = res * a ; a = a * a; b >>= 1;} return res;}

const int N=200005;

//------------------------------------------------------------------------

void solve(){
// tourist bhaiya ka solution

    // int n, c, q;
    // cin >> n >> c >> q;
    // string s;
    // cin >> s;
    // vector<long long> l(c), r(c);
    // vector<long long> len(c + 1);
    // len[0] = n;
    // for (int i = 0; i < c; i++) {
    //   cin >> l[i] >> r[i];
    //   len[i + 1] = len[i] + (r[i] - l[i] + 1);
    // }
    // while (q--) {
    //   long long k;
    //   cin >> k;
    // //   assert(k <= len[c]);
    //   for (int i = c - 1; i >= 0; i--) {
    //     if (k > len[i]) {
    //       k = l[i] + (k - len[i] - 1);
    //     }
    //   }
    //   assert(k <= n);
    //   cout << s[k - 1] << '\n';
    // }

    int n,c,q; cin >> n >> c >> q;
     string s; cin >> s;
     vector<pair<int,int>> cc(c+1);
     rep_a(i,1,c+1)
     {
        cin >> cc[i].first >> cc[i].second;
        cc[i].first--;
        cc[i].second--;
     }
     vector<pair<int,int>> v(c+1);
     v[0].first = 0; v[0].second = n-1;
     rep_a(i,1,c+1)
     {
        v[i].first = v[i-1].second+1;
        v[i].second = v[i].first + (cc[i].second - cc[i].first);
     }
    //  for(int i=0;i<=c; i++)
    //  {
    //     cout << v[i].first << " " << v[i].second << endl;
    //  }
     for(int i=0; i<q; i++)
     {
        int ind; cin >> ind;
        ind--;
        while(ind >= n)
        {
            for(int j=1; j<=c; j++)
            {
                if(ind >= v[j].first && ind <= v[j].second)
                {
                    ind = cc[j].first + (ind - v[j].first);
                    break;
                }
            }
        }
        cout << s[ind] << endl;
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