#include <cstdio>
#include <iostream>
#include <algorithm>

int main () {
	int test_cases;
	std::ios_base::sync_with_stdio(false);
	std::cin >> test_cases;
	while (test_cases--) {
		long long n;
		long long m;
		std::cin >> n >> m;
		if ((n % 2 == 0 || m % 2 == 0) && (std::min(n, m) > 1 || std::max(n, m) < 3))
			std::cout << "Yes" << std::endl;
		else
			std::cout << "No" << std::endl;
	}
	return 0;
}
// Since the ending cell must be adjacent to the starting cell, the found path can be immediately extended one more step, into a cycle which passes through all the cells of the maze. Such a cycle is called a Hamiltonian cycle. Note that in this case it doesn’t matter which is the starting cell.

// An NxM maze has a Hamiltonian cycle if and only if:

// min{N,M}=1 and max{N,M}=2, OR
// min{N,M}>=2 and at least one of N and M is even.