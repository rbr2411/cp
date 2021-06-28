#include <bits/stdc++.h>
using namespace std;

void possibleSubsets(char A[], int n)
{
    for(int i = 0; i < (1 << n); i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i & (1 << j))
                cout << A[j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    char A[] = {'a', 'b', 'c', 'd', 'e'};
    int n = sizeof(A)/sizeof(A[0]);
    possibleSubsets(A, n);
}