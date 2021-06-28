// Time Complexity: O(log min(a, b))
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    int a = 15, b = 5;
    cout << gcd(a,b) << endl;
}
