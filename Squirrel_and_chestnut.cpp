#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

const int sz = (int)1e4 + 5;
int ti[sz];
int pi[sz];

bool isPossible(int m, int n, int k, int time) {
  vector<int> nutsArray(m, 0);

  for (int i = 0; i < m; i++) {
    if (time - ti[i] < 0)
      nutsArray[i] = 0;
    else
      nutsArray[i] = 1 + (time - ti[i]) / pi[i];
  }

  sort(nutsArray.begin(), nutsArray.end(), greater<int>());

  long long int nc = 0;

  for (int i = 0; i < min(n, m); i++) {
    nc += nutsArray[i];
  }

  return nc >= k;
}

void solve(int m, int n, int k) {
  int lo = 1, hi = INT_MAX;
  int ans = INT_MAX;

  while (lo <= hi) {
    int mid = (lo + hi) >> 1;

    if (isPossible(m, n, k, mid)) {
      ans = min(ans, mid);
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  if (ans == INT_MAX) {
    cout << 0 << endl;
    return;
  }
  cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--) {
    int m, n, k;
    cin >> m >> n >> k;

    for (int i = 0; i < m; i++) {
      cin >> ti[i];
    }

    for (int i = 0; i < m; i++) {
      cin >> pi[i];
    }

    // cout << isPossible(m, n, k, 1) << endl;
    solve(m, n, k);
  }
  return 0;
}