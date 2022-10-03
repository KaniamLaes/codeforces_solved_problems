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
    // What I did is, if we have to place a number of '(' and b number of ')' in place of the question marks,
    // then it will certainly work to first place a '(' and then place all b closing brackets. 
    // (We need to always maintain that count( '(' ) > count( ')' ). 
    // The method that is second best to follow the criteria, is we instead place '(' on question marks 1 to a-1, 
    // and a+1. If this produces a valid sequence different from the previous one, then the first answer is not 
    // unique. Else, there is only a single solution to the problem.
    string s; cin >> s;
        ll n = s.length();
 
        ll sum = 0, unk = 0;
        for(ll i=0; i<n; i++){
            if(s[i] == '(')sum++;
            else if(s[i] == ')')sum--;
            else unk++;
        }
 
        ll pos = (unk-sum)/2;
        ll neg = unk - pos;
        bool here = 0;
        bool tru = 1; // not unique
        sum = 0;
 
        // Either you cant flip, or flipping is wrong
        if(pos == 0 || neg == 0)tru = 0;
        
        for(ll i=0; i<n; i++){
            if(s[i] == '?'){
                if(pos > 1){s[i] = '('; pos--;}
                else if(pos ==1 && here == 0){s[i]=')'; here = 1;}
                else if(pos ==1 && here == 1){s[i]='('; pos--;}
                else s[i] = ')';
            }
 
            if(s[i] == '(')sum++;
            else sum--;
            if(sum < 0)tru = 0;
        }
 
        if(!tru)cout << "YES\n";
        else cout << "NO\n";
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