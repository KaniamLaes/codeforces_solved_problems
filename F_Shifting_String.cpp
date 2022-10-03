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


// #define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
// //-------------------------------------------------------------------------

// //------------------------------------------------------------------------
// ll stringtointeger(string s){  ll num; num = stoi(s); return num;}

// ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
// ll pwr(ll a, ll b) { ll res = 1; while (b > 0) {if (b & 1) res = res * a ; a = a * a; b >>= 1;} return res;}

// const int N=200005;

// //------------------------------------------------------------------------
// int findRotation(string s){
    
//     int n=s.length()-1;
//     string t=s.back()+s.substr(0,n);  
//     int ans=1;
//     // if(t==s) return ans;
//     while(t!=s){
//         ans++;
//         t=t.back()+t.substr(0,n);
//     }
//     // cout<<t<<el;
//     return ans;
// }
int lcm(int x,int y){
    return ((x*y)/__gcd(x,y));
}
// void solve(){
//     int n; cin>>n; 
//     string s; cin>>s;
//     vi a(n);
//     rep(i,n){
//         cin>>a[i];
//         a[i]--;
//     }
//     vector<vi>v;
//     sll done;
//     rep(i,n){
//         if(done.count(i)) continue;
//         vi temp={i};
//         int cur=i;
//         while(a[cur]!=i){
//             temp.pb(a[cur]); cur=a[cur];
//         }
//         for(auto j:temp){
//             done.insert(j);
//         }
//         v.pb(temp);
//     }
//     vector<string>cy;
//     for(auto i:v){
//         string temp;
//         for(auto j:i){
//             temp.pb(s[j]);
//         }
//         cy.pb(temp);
//     }
//     int ans=1;
//     for(auto i:cy){
//         ans=lcm(ans,findRotation(i));
       
//     }
//     cout<<ans<<el;
// }

// signed main()
// {
//     ios_base::sync_with_stdio(0); cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//     {

//        solve();

//     }

//     // return 0;
// }



#include <bits/stdc++.h>
using namespace std;

int n, p[201], vis[201];
string s;
long long res;

void solve() {
    cin >> n >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        vis[i] = 0;
    }
    res = 1;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int t = i;
        string s2;
        while (!vis[t]) s2 += s[t], vis[t] = 1, t = p[t];
        string s3 = s2;
        s3 += s3[0];
        s3.erase(0, 1);
        long long req = 1;
        while (s3 != s2) {
            s3 += s3[0];
            s3.erase(0, 1);
            req++;
        }
        res = lcm(res, req);
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}