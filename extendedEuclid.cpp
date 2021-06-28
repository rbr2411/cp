// ax + by = d
// O(log(max(a,b)))
#include <bits/stdc++.h>
using namespace std;

int gcdExtended(int a, int b, int *x, int *y)
{
    if(a==0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive calls
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive call
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}

int main()
{
    int a = 305, b = 1025;
    int x = 0, y = 0;
    cout << gcdExtended(a, b, &x, &y) << endl;
    cout << "Coefficients are: " << x << " " << y << endl;
}