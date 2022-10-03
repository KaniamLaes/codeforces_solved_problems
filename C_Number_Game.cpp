//  “Work like there is someone working 24 hours a day to take it away from you.”

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

const int N = 50000;

void player_1(){
	cout << "Ashishgup" << endl;
}

void player_2(){
	cout << "FastestFinger" << endl;
}

bool check_prime(int n){
	for(int i = 2; i < min(N, n); i++)
		if(n % i == 0)
			return 0;
	return 1;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		bool lose = (n == 1);
		if(n > 2 && n % 2 == 0){
			if((n & (n - 1)) == 0)
				lose = 1;
			else if(n % 4 != 0 && check_prime(n / 2))
				lose = 1;
		}
		if(lose)
			player_2();
		else player_1();
	}
}

// If n is divisible by 4 then Ashishgup can divide n by its largest odd factor after which n becomes of the form 2x where x>1, so Ashishgup wins.