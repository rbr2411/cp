#include <bits/stdc++.h>
using namespace std;

void primeFactorize(int n)
{
    if(n == 1 || n == 0)
    {
        cout << "No prime factors" << endl;
        return;
    }

    if(n < 0)
        n *= -1;

    int a = sqrt(n);
    for(int i = 2; i <=a; i++)
    {
        if(n % i == 0)
        {
            cout << "Prime factor: " << i;
            int power  = 0;
            while(n % i == 0)
            {
                n/= i;
                power++;
            }
            cout << "; power: " << power << endl;
        }
    }

    if(n != 1)
    {
        cout << "Prime factor: " << n << "; power: 1" << endl;
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    primeFactorize(n);
}