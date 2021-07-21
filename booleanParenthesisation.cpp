#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> dp;
// Memoized version
int solve(string s, int i, int j, bool isTrue)
{
    if(i > j)
        return dp[i][j][isTrue] = 0;
    
    if(i == j)
    {
        if(isTrue)
            return dp[i][j][isTrue] = (s[i] == 'T');    
        else return dp[i][j][isTrue] = (s[i] == 'F');
    }
    if(dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    int ans = 0;
    for(int k = i+1; k <= j-1; k += 2)
    {
        int lT, lF, rT, rF;
        if(dp[i][k-1][1] != -1)
            lT = dp[i][k-1][1];
        else
        {
            dp[i][k-1][1] = solve(s, i, k-1, true);
            lT = dp[i][k-1][1];
        }

        if(dp[i][k-1][0] != -1)
            lF = dp[i][k-1][0];
        else 
        {
            dp[i][k-1][0] = solve(s, i, k-1, false);
            lF = dp[i][k-1][0];
        }

        if(dp[k+1][j][1] != -1)
            rT = dp[k+1][j][1];
        else
        {
            dp[k+1][j][1] = solve(s, k+1, j, true);
            rT = dp[k+1][j][1];
        }

        if(dp[k+1][j][0] != -1)
            rF = dp[k+1][j][0];
        else 
        {
            dp[k+1][j][0] = solve(s, k+1, j, false);
            rF = dp[k+1][j][0];
        }
        if(s[k] == '^')
        {
            if(isTrue) 
                ans += lT * rF + rT * lF;
            else ans += lT * rT + lF * rF;
        }

        else if(s[k] == '&')
        {
            if(isTrue)
                ans += lT * rT;
            else ans += lT * rF + lF * rT + lF * rF;
        }

        else
        {
            if(isTrue)
                ans += lT * rT + lF * rT + lT * rF;
            else ans += lF * rF;
        }
    }
    return dp[i][j][isTrue] = ans;
}
// Recursive Version
// int solve(string s, int i, int j, bool isTrue)
// {
//     if(i > j)
//         return 0;
    
//     if(i == j)
//     {
//         if(isTrue)
//             return s[i] == 'T';
//         else return s[i] == 'F';
//     }
//     int ans = 0;
//     for(int k = i+1; k <= j-1; k += 2)
//     {
//         int lT = solve(s, i, k-1, true);
//         int lF = solve(s, i, k-1, false);
//         int rT = solve(s, k+1, j, true);
//         int rF = solve(s, k+1, j, false);

//         if(s[k] == '^')
//         {
//             if(isTrue) 
//                 ans += lT * rF + rT * lF;
//             else ans += lT * rT + lF * rF;
//         }

//         else if(s[k] == '&')
//         {
//             if(isTrue)
//                 ans += lT * rT;
//             else ans += lT * rF + lF * rT + lF * rF;
//         }

//         else
//         {
//             if(isTrue)
//                 ans += lT * rT + lF * rT + lT * rF;
//             else ans += lF * rF;
//         }
//     }
//     return ans;
// }

int main()
{
    string s = "T|T&F^T";
    int n = s.length();
    dp.assign(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
    cout << solve(s, 0, s.length()-1, true) << endl;
}