// CodeForces 26 A
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    // get the list of primes <= n
    vector<bool> is_primes(n+1, true);
    vector<int> primes;
    is_primes[0] = is_primes[1] = false;
    for(int i = 2; i <= n; i++)
    {
        if(is_primes[i] && i * i <= n)
        {
            for(int j = i * i; j <= n; j += i)
                is_primes[j] = false;
        }
    }

    for(int i = 2; i <=n; i++)
        if(is_primes[i])
            primes.push_back(i);

    int m = primes.size();
    int res = 0;
    for(int i = 6; i <= n; i++)
    {
        int cnt = 0;
        for(auto it = primes.begin(); it!= primes.end(); it++)
        {
            if(i % (*it) == 0)
                cnt++;
        }
        if(cnt == 2)
            res++;
    }
    cout << res << endl;
    return 0;
}