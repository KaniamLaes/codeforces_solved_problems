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

ll stringtointeger(string s){  ll num; num = stoi(s); return num;}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll pwr(ll a, ll b) { ll res = 1; while (b > 0) {if (b & 1) res = res * a ; a = a * a; b >>= 1;} return res;}

const int N=200005;

//------------------------------------------------------------------------

void solve(){
    int n; cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++ ) cin>>a[i];
    int ans=n;
    int pf=0,sf=0;
    for(int i=1;i<=n;i++){
        pf+=a[i];
    }
    sort(a.begin()+1,a.end());
    for(int i=1;i<=n;i++){
        pf-=a[i];
        sf+=a[i];
        int rq=i*a[i]-sf;
        if(pf>=rq)ans--;
    }cout<<ans<<el;
    
}
/**
 We can solve it greedily. What I have done is that I initially supposed all guys to be monks and then 
 greedily iterated over the sorted array and check if monks can be reduced or not.
Let suppose our array was [2,5,6,10,8,3] so after sorting it becomes [2,3,5,6,8,10]. 
Now let suppose all members decided to be monks so monks = 6. 
So we have coins = total sum of all elements of array which is 34. 
let say our person 1 dont want to be monk., then our coins become 32 and we have person 1 as a town member 
but theres no need to give him coins as theres only one member in town so our monks now reduce to 5. 
Now we again check for person 2. If he dont wanna be a monk then we will have coins = 32 - 3 = 29 
which we can distribute. 
and our town people now become [2,3] so we know all those people in town will have coins equal to the 
maximum coins that is 3. so 2 members will have 3 coins each and we have currently (2+3) coins = 5. 
so required coins = (2 * 3) - (2 + 3) = 1, obviously we can take 1 coin from those 29 coins 
and give to person 1, so that all have 3 coins each which reduces the number of monks to 4. 
Similarly we go to person 3 and check if he can be member of town. so now members =[2,3,5] and 
coins = 29 - 5 = 24. We want to make all person coins = 5. IN order to do it 
we require (5 * 3 ) - (2 + 3 + 5) = 5 coins. we again can take 5 coins from 24 coins and give distribute 
it among 3persons so that all have 5 coins each. now our monk becomes 3. same way we check for all 
the persons and for any index we get required coins<coins offered by monks that time we get the 
minimum number of monks.
 */

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