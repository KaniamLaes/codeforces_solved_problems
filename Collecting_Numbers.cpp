//  “Work like there is someone working 24 hours a day to take it away from you.”

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define db double
#define el endl
#define ld long double
#define pb push_back
#define all(x) x.begin(), x.end()
#define asc(x) sort(x.begin(), x.end())
#define des(x) sort(x.begin(), x.end(), greater<int>())
#define rep(i, n) for (int i = 0; i < n; i++)
#define rev(i, n) for (int i = n; i >= 0; i--)
#define rep_a(i, a, n) for (int i = a; i < n; i++)

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

#define print(arr)                                     \
    for (auto it = arr.begin(); it != arr.end(); ++it) \
        cout << *it << " ";                            \
    cout << endl;
//-------------------------------------------------------------------------

//------------------------------------------------------------------------
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
int f[N];
void solve()
{
    // int n;
    // cin >> n;
    // vi a(n);
    // rep(i, n) cin >> a[i];
    // int chk = 1, ans = 0;
    // rep(i, n - 1)
    // {
    //         if(count(all(a),a[i])==n) break;
    //     if (a[i] != -1  )
    //         chk = a[i];
    //     else continue;
    //     a[i] = -1;
    //     rep_a(j, i + 1, n)
    //     {
    //         if (a[j] == chk + 1)
    //             chk++, a[j] = -1;
    //     }
    //     ans++;
    // }
    // cout << ans << el;
    // cout << ans << el;


    int n, ans = 1;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a)
        cin >> x, x--;
    for (int i = 0; i < n; i++)
        b[a[i]] = i;
    for (int i = 1; i < n; i++)
        ans += b[i] < b[i - 1];
    cout << ans;

    // int n, i, ans = 0;
    // cin >> n;
    // while (n--)
    // {
    //     cin >> i;
    //     ans += !f[i - 1];
    //     ++f[i];
    // }
    // cout << ans;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    {

        solve();
    }

    return 0;
}