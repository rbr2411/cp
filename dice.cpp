// Iterative C++ program to compute modular power
#include <iostream>
using namespace std;

/* Iterative Function to calculate (x^y)%p in O(log y) */
int power(long long x, unsigned int y, int p)
{
	int res = 1;	 // Initialize result

	x = x % p; // Update x if it is more than or
				// equal to p

	if (x == 0) return 0; // In case x is divisible by p;

	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res*x) % p;

		// y must be even now
		y /=2; // y = y/2
		x = (x*x) % p;
	}
	return res;
}

// Driver code
int main()
{
	int x = 2;
	int y;
  	cin >> y;
	int p = 1e9 + 7;
	cout << power(x, y-1, p);
	return 0;
}

// This code is contributed by shubhamsingh10
