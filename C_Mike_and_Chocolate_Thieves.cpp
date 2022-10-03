#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define int long long 




int solve(int mid)
{
	int ways = 0;
	for (int k = 2; ways < (int)1e16; k++)
	{
		int p = k * k * k;
		if (p > mid) break;
		ways += mid / p;
	}
	return ways;
}

int32_t main()
{

    int m;
	cin>>m;
	int l = 0, r = (int)1e16;
	while(r - l > 1)
	{
		int mid = (l + r) / 2;//mid is the assumed n
		if (solve(mid) >= m)
			r = mid;
		else
			l = mid;
	}
	if (solve(r) == m)
		cout<<r<<endl;
	else
		cout<<-1<<endl;

	return 0;
}