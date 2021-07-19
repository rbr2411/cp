// Printing longest common subsequence of two strings
#include <bits/stdc++.h>
using namespace std;
string lcs(string x, string y, int n, int m)
{
    int dp[n+1][m+1];
    string ans = "";
    for(int i = 0; i < n+1; i++)
        dp[i][0] = 0;
    
    for(int j = 1; j < m+1; j++)
        dp[0][j] = 0;
    
    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < m+1; j++)
        {
            if(x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    int i = n, j = m;
    while(i > 0 && j > 0)
    {
        if(x[i-1] == y[j-1])
        {
            ans += x[i-1];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j] > dp[i][j-1])
            {
                i--;
            }
            else j--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
  string x = "acbcf";
  string y = "abcdaf";
  int n = x.length();
  int m = y.length();
  cout << lcs(x, y, n, m) << endl;
  return 0;
}