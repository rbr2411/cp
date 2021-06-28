// SPOJ Prime1
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int m, n;
        cin >> m >> n;

        vector<bool> is_primes(n+1, true);
        is_primes[0] = is_primes[1] = false;

        for(int i = 2; i <= n; i++)
        {
            if(is_primes[i] && (long)i * i <= n)
            {
                for(int j = i * i; j <= n; j += i)
                    is_primes[j] = false;
            }
        }

        for(int i = m; i <= n; i++)
        {
            if(is_primes[i])
                cout << i << endl;
        }
        cout << "\n" ;
    }
    return 0;
}