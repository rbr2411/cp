#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcdExtended(ll a, ll b, ll* x, ll* y)
{
    if(a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b/a)* x1;
    *y = x1;
    return gcd;
}


ll findMinX(int num[], int rem[], int k)
{
    ll res = 0;
    ll N = 1;
    for(int i = 0; i < k; i++)
        N *= num[i];
    
    ll Ni[k];
    for(int i = 0; i < k; i++)
    {
        Ni[i] = N/num[i];
    }

    ll Xi[k];
    for(int i = 0; i < k; i++)
    {
        ll y = 0;
        ll gcd = gcdExtended(Ni[i], num[i], &Xi[i],&y);
    }

    for(int i = 0; i < k; i++)
    {
        res += (rem[i] * Ni[i] * Xi[i]) % N;
    }
    res = (res % N + N) % N; // In order to ensure res is positive
    return res;
}


int main()
{
    int num[] = {5,7};
    int rem[] = {1,3};
    int k = sizeof(num)/sizeof(num[0]);
    cout << findMinX(num,rem,k) << endl;
    return 0;
}