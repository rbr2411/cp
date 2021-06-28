#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int div = 0;
    // Naive Approach-- O(n)
    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
            div++;
    }       
    if(div == 2)
        cout <<"Using Naive Approach: "<< n << " is prime.\n";
    else cout << "Not a prime\n";

    div = 0;
    //O(sqrt(n))
    if(n == 1)
    {
        cout << "Not a prime\n";
        return 0;
    }
    else if(n == 2)
    {
        cout << n << " is prime\n";
        return 0;
    }
    for (int i = 1; i <= ceil(sqrt(n)); i++)
    {
        if(n % i == 0)
            div++;
    }
    if(div == 1)
        cout << "Using Better Approach: " << n << " is prime.\n";
    else cout << "Not a prime\n";

    // Sieve of Eratosthenes
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false; 
    for (int i = 2; i <= n; i++) 
    {
  	    if (is_prime[i] && (long long)i * i <= n)
        {
			for (int j = i * i; j <= n; j += i) 
				is_prime[j] = false; 
  	    } 
    }
}