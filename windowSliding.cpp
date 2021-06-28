#include <bits/stdc++.h>
using namespace std;

int main()
{
    // fixed size window sliding
    /* int arr[] = {12, 23, 1, 22, 16, 17, 8, 14, 29};
    int k = 3;
    int n = sizeof(arr)/sizeof(arr[0]);

    int maxSum = 0, windowSum = 0;
    for(int i = 0; i < k; i++)
        windowSum += arr[i];
    maxSum = windowSum;

    for(int i = k; i < n; i++)
    {
        windowSum = windowSum + arr[i] - arr[i-k];
        maxSum = max(maxSum, windowSum);
    }
    cout << maxSum << endl; */

    // Variable Sized Window Sliding
    // length of smallest subarray with sum >= k
    int arr[] = {12,28,83,4,25,26,25,2,25,25,25,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int targetSum = 213, currWindowSum = 0;
    int minWindowSize = INT32_MAX;
    int windowStart = 0, windowEnd = 0;
    for(windowEnd = 0; windowEnd < n; windowEnd++)
    {
        currWindowSum += arr[windowEnd];
        while(currWindowSum >= targetSum)
        {
            minWindowSize = min(minWindowSize, windowEnd - windowStart + 1);
            if(minWindowSize == 1)
            {
                cout << minWindowSize << endl;
                return 0;
            }
            currWindowSum -= arr[windowStart];
            windowStart++;
        }
    }
    cout << minWindowSize << endl;
    return 0;
}