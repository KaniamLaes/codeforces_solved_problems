//  “Work like there is someone working 24 hours a day to take it away from you.”

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ld long double
#define db double
#define el '\n'
#define ld long double
#define pb push_back
#define all(x) x.begin(), x.end()
#define asc(x) sort(x.begin(), x.end())
#define des(x) sort(x.begin(), x.end(), greater<int>())
#define rep(i, n) for (int i = 0; i < n; i++)
#define rev(i, n) for (int i = n; i >= 0; i--)
#define rep_a(i, a, n) for (int i = a; i < n; i++)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define int long long

const long long MOD = 998244353;
const long long INF = 1e9 + 10;
const long long INFLL = 1e18;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef set<int> si;
typedef set<ll> sll;

typedef map<int, int> mii;
typedef map<ll, ll> mll;

#define yes cout << "YES\n"
#define no cout << "NO\n"

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

ll stringtointeger(string s)
{
    ll num;
    num = stoi(s);
    return num;
}
ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }
ll pwr(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

const int N = 200005;

//------------------------------------------------------------------------

/**
 *
 * Explanation
 *
 * -->(1,j) at cuur_time; time will be curr_time+2*(m-col)+1
 *
 * now for first row, we will take max(a[1][j]+1+m-j+1+m-i);
 * for 2nd row max(a[2][j]+1+(j-i))
 *
 * for all j>i; for 1st case
 * for all j>=i
 *
 * reverse for (2,i)
 */
void solve()
{
    int m, i = 0, j = 0, ans = 0;
    
     cin>>m;
     vector<vl>a(3,vl(m+1,0));
        rep_a(i,1,3)
        {
            rep_a(j,1,m+1)
            {
                cin>>a[i][j];
            }
        }
 
        vector<vl>suffix_max_minus(3,vl(m+5,-INT_MAX));
        vector<vl>suffix_max_plus(3,vl(m+5,-INT_MAX));
 
        rep_a(i,1,3)
        {
            for(j = m;j>0;j--)
            {
                suffix_max_minus[i][j] = max(suffix_max_minus[i][j+1],a[i][j] - j);
                suffix_max_plus[i][j] = max(suffix_max_plus[i][j+1],a[i][j] + j);
            }            
        }
 
        ll row,col;
        row = 1;
        col = 1;
 
        ll moves = 0;
        ll curr_time = 0;
 
        ans = 2*m - 1;
        ans = max(ans,suffix_max_minus[1][2] + 2*m +1);
        ans = max(ans,suffix_max_plus[2][1]);
        for(moves = 1;col <= m; moves++)
        {
            if(moves%2 == 0)
            {
                col++;
                curr_time = max(curr_time + 1,a[row][col] + 1);
                ll curr;
                if(col == m)
                {
                    curr = max(curr_time + 1,a[(row == 1) ? 2 : 1][m] + 1);
                }
                else
                {
                    i = row;
                    j = col;
                    curr = curr_time + 2*(m - col) + 1;
                    if(row == 1)
                    {
                        curr = max(curr, suffix_max_minus[1][j+1] + 2*m + 2 - col);
                        curr = max(curr,suffix_max_plus[2][j] - col + 1);
                    }
                    else
                    {
                        curr = max(curr, suffix_max_minus[2][j+1] + 2*m + 2 - col);
                        curr = max(curr,suffix_max_plus[1][j] - col + 1);                        
                    }
                }
                ans = min(ans,curr);
 
            }
            else if(moves%4 == 1)
            {
                row++;
                curr_time = max(curr_time + 1,a[row][col] + 1);
            }
            else
            {
                row--;
                curr_time = max(curr_time + 1,a[row][col] + 1);
            }
 
        }
        cout<<ans<<"\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}