#include <iostream>
#include <vector>
using namespace std;

vector<int> memo(100, 0);
int fib(int n) 
{
    if(n <= 1) return n;
    if(memo[n] != 0) return memo[n];
    memo[n] = fib(n-1) + fib(n-2);
    return memo[n];
}

int Fib(int n)
{
    if(n == 0) return 0;
    int dp[n+1];
    // Define base cases
    dp[0] = 0;
    dp[1] = 1;
    // Iterate over all other values
    for(int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];  
    return dp[n];
}

int main() 
{
    cout << Fib(20) << endl;
    cout << fib(20) << endl;
    return 0;
}