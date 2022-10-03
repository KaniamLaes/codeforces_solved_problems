#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>

#define rep(i, s, n) for(int i=int(s); i<=int(n); ++i)
using namespace std;
const int mx = 1e5 + 10, mod = 1e9+7;

int n, k, m, t;
int A[mx], B[mx], C[mx], D[mx];
multiset<int> buttons;

int main()
{
	//rf;// wf;
	ios::sync_with_stdio(0);

	cin >> t;
	while(t--)
	{
		buttons.clear();
		cin >> n >> k >> m;

		for(int i = 1; i<=n; ++i)
			cin >> A[i];

		for(int i = 1; i <=n; ++i)
		{
			cin >> B[i];
			A[i] -= B[i];
		}

		for(int i = 1; i<=k; ++i)
		{
			cin >> C[i];
			buttons.insert(C[i]);
		}
		for(int i = 1; i<=m; ++i)
		{
			cin >> D[i];
			buttons.insert(D[i]);
		}

		multiset<int>::iterator it;
		long long ans = 0;

		// sort(A+1, A+n+1);

		for(int i = 1; i<=n; ++i)
		{
			if(buttons.empty() or *buttons.begin() > A[i])
				ans += A[i];
			else
			{
				it = buttons.upper_bound(A[i]);
				it--;

				ans += A[i] - *it;
				buttons.erase(it);
			}
		}

		cout << ans << '\n';
	}
	return 0;
}