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
// #define int long long


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

void solve(){ //i am the best 
    int n; cin>>n;
    vl t(n),x(n);
    rep(i,n) cin>>t[i]>>x[i];
    t.pb(1e18);

    ll ans=0;
    ll curx=0,nxt=0,curt=0;
    // curx: pos of the robot 
    // nxt: destination of the robot
    // curt:current time 
    rep(i,n){
        ll dx=nxt-curx;
        ll dt=t[i]-curt;

        ll dir=(dx>0)?1:-1;
        ll steps=min(abs(dx),dt);
        curt+=dt;
        curx+=steps*dir;
        if(curx==nxt){//curx==nxt-->robot not moving ;command received 
            nxt=x[i];
        }//else, robot is movin lignore the command

        // first check if [cyrx,nxt] contains x[i]
        if(min(curx,nxt)<=x[i] && x[i]<=max(curx,nxt)){
            // computing the ans in the same loop
            if(abs(curx-x[i])<=t[i+1]-t[i]){
                // now check that [curx,curx+sign*(t[i+1]-t[i])] contains x[i];
                ++ans; //previous was successful
            }
        }
    }
    cout<<ans<<el;
}

int main()
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



// full explanation
// Sample 1:
// 3
// 1 5 --> at time 1, move to point 5.
//   - RECEIVED; at time 1, we were at 0 (robot's current destination)
//   - Not a success! we did not reach 5 before time 3!
// 3 0 --> at time 3, move to point 0.
//   - IGNORED; at time 3, robot is still moving towards point 5 (and is at x = 2).
//   - Not a success! Never reached 0.
// 6 4 --> at time 6, move to point 4.
//   - RECEIVED; at time 6, robot is at 5 (robot's current destination)
//   - a SUCCESS! We eventually hit point 4 (at time 7)


// Insight: a robot is either moving or at its destination
// --> Simplify the condition for ignoring. Not Moving iff At Destination
//   (where destination := the most recent target it was given that wasn't ignored)

// ## Simulating the robot
//   So, just keep track of two things about the robot:
//   1) Where is it? (`cur`)
//   2) Where is it going? (`nxt`)

//   (And keep track of the current time as you iterate over events)
//   Maintain these 2 state values over time.

// ## Producing the answer
//   How do you determine if a command was successful?
//   A command (t_i, x_i) is successful iff [cur, ncur] includes x_i
//   cur := position of robot at t_{i}
//   ncur := position of robot at t_{i+1}
//   NOTE: This is not the same as [cur, nxt] includes x_i; although the next command m ay be ignored & not affect `nxt`, the condition for success still depends on t_{i+1}
