// CodeForces 17 A
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<bool> is_prime(n+1, true);
    vector<int>primes;
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= n; i++)
    {
        if(is_prime[i] && i * i <= n)
        {
            for(int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for(int i = 2; i <= n; i++)
    {
        if(is_prime[i])
            primes.push_back(i);
    }
    int cnt = 0;
    int m = primes.size();
    for(int i = 0; i < m - 2; i++)
    {   
        if(cnt < k)
        {
            if(primes[i] + primes[i+1] < primes[m-1] && find(primes.begin()+i+2,primes.end(),primes[i] + primes[i+1] + 1) != primes.end())
                cnt++;
        }
        else 
        {
            cout << "YES";
            return 0;
        }
    }
    cnt == k ? cout << "YES": cout << "NO";
    return 0;
}