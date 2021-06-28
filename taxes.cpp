// CodeForces 735 D
// Using Goldbach Conjecture: Every even integer greater than 2 can be written as 
// decomposition of 2 prime numbers.
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    int div = 0;
    int a = ceil(sqrt(n));
    if(n == 2)
        return true;
    // for n > 2, a < n holds true.
    // thus till a, excluding 1, there should not be any divisor of a prime no.
    for(int i = 2; i <= a; i++)
    {
        if(n % i == 0)
            div++;
        if(div > 0) 
            return false;
    }
    return (div == 0);
}
int main()
{
    int n;
    cin >> n;
    // Check if n is prime: If yes, print 1
    if(isPrime(n))
        cout << 1 << endl;
    // Now if even composite then by G.C. print 2
    else if(n % 2 == 0)
        cout << 2 << endl;
    // odd composites start from 9
    else
    {   
        // if odd composite can be written as sum of two primes, print 2.
        // one of the prime would be 2. 9 = 2 + 7
        if(isPrime(n-2))
            cout << 2 << endl;
        else cout << 3 << endl;// 27 = 3 + 24 = 3 + 11 + 13 
    }
    return 0;
}