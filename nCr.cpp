#include <bits/stdc++.h>
using namespace std;

double nCr(int n, int r)
{
    if(r > n/2)
        r = n-r;
    
    double res = 1.0;
    for(int i = 0; i < r; i++)
        res *= 1.0 * (n-i)/(i+1);

    return res;
}


int main()
{
    int n,r;
    cin >> n >> r;
    cout << nCr(n,r) << endl;
}