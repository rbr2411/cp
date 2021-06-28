#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isPrime(ll n)
{
    if(n < 2)
        return false;
    int a = floor(sqrt(n));
    int div = 0;
    for(int i = 1; i <= a; i++)
    {
        if(n % i == 0)
            div++;
        if(div > 1)
            return false;
    }
    return (div == 1);
}

bool isSquare(ll n)
{
    ll a = sqrt(n);
    return (a * a == n);
}
int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        ll n;
        cin >> n;
        if(n == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        if(!isSquare(n))
        {
            cout << "NO" << endl;
            continue;
        }
        if(!isPrime(sqrt(n)))
        {
            cout << "NO" << endl;
            continue;
        }
        
        cout << "YES" << endl;
    }
}