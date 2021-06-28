#include <bits/stdc++.h>
using namespace std;
# define M 3
# define N 4

void setToZeros(int a[M][N])
{
    vector<int> rows, columns;

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(a[i][j] == 0)
                {
                    rows.push_back(i);
                    columns.push_back(j);
                }
        }
    }

    for(int i = 0; i < rows.size(); i++)
    {
        for(int j = 0; j < N; j++)
        {
            a[rows[i]][j] = 0;
        }
    }

    for(int i = 0; i < columns.size(); i++)
    {
        for(int j = 0; j < M; j++)
        {
            a[j][columns[i]] = 0;
        }
    }
}

void printArr(int a[M][N])
{
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{
    srand(time(0));
    
    int randMax = 47;
    int arr[M][N];
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            arr[i][j] = rand() % randMax;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    setToZeros(arr);
    cout << "---------------------" << endl;
    printArr(arr);
}