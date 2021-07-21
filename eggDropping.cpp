#include <bits/stdc++.h>
using namespace std;
int solve(int e, int f)
{
    if(f == 0 || f == 1 || e == 1)
        return f;

    int mn = INT_MAX;

    for(int k = 1; k <= f; k++)
    {
        int temp = max(solve(e, f-k), solve(e-1, k-1)) + 1;
        mn = min(mn, temp); 
    }
    return mn;
}
int main()
{
    int e = 2;
    int f = 20;
    cout << solve(e, f) << endl;
}