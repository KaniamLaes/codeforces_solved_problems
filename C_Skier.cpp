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
    string s;
        cin >> s;
        // we need a map storing two pairs, 
        // one for the point Skier is going from, let's say p1
        // another for the point Skier is going to, let's say p2
        map<pair<pair<int,int>,pair<int,int>>,bool> m;
        int x=0,y=0,ans=0;
        
        for(char c : s){
            pair<int,int> p1,p2;
            p1=make_pair(x,y);
            // for four directions, store the coordinate (x,y) to a pair
            if(c=='S') {
                p2 = make_pair(x,--y);
            }else if(c=='N'){
                p2 = make_pair(x,++y);
            }else if(c=='W'){
                p2 = make_pair(--x,y);
            }else if(c=='E'){
                p2 = make_pair(++x,y);
            }
            // if this point is visited, add 1
            if(m[{p1,p2}]) ans++;
            else {
                // if not, add 5
                ans+=5;
                // set both from & to pair to true
                m[{p1,p2}]=m[{p2,p1}]=true;
            }
        }
        cout << ans << "\n";
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