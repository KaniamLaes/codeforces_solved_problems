#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include "/home/upayan/Documents/CP/debug.h"
	#define dbg(x...) cerr << "[" << #x << "] = ["; __print(x); _print();
#else
	#define dbg(x...)
#endif

#define INF INT_MAX
#define all(x) (x).begin() , (x).end()

#define int long long

void solve() {
	int n , k; cin >> n >> k; int a[n]; for (int i = 0 ; i < n ; i++) {cin >> a[i];}
	bool arr[n - 1]; for (int i = 0 ; i + 1 < n ; i++) {arr[i] = (a[i] < 2 * a[i + 1]);}
	int ans = 0 , cnt = 0;
	for (int i = 0 ; i + 1 < n ; i++) {
		if (arr[i]) {cnt++;}
		else {ans += max(0LL , cnt - k + 1); cnt = 0;}
	} 
	ans += max(0LL , cnt - k + 1);
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int tt = 1; cin >> tt;
	for (int i = 1 ; i <= tt ; i++) {
		//cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}