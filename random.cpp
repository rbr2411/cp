#include <bits/stdc++.h>
using namespace std;
#define N 3

// Time Complexity: O(N^2)
// We cannot do better than O(N^2), since any algo
// that rotates an array must cover all elements
void rotateClockwise90(int arr[N][N])
{
    for(int i = 0; i < N/2; i++)
    {
        for(int j = i; j < N-1-i; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[N-1-j][i];
            arr[N-1-j][i] = arr[N-1-i][N-1-j];
            arr[N-1-i][N-1-j] = arr[j][N-1-i];
            arr[j][N-1-i] = temp;
        }
    }
}

void rotateAntiClockwise90(int arr[N][N])
{
    for(int i = 0; i < N/2; i++)
    {
        for(int j = i; j < N-1-i; j++)
        {
            int tmp = arr[i][j];
            arr[i][j] = arr[j][N-1-i];
            arr[j][N-1-i] = arr[N-1-i][N-1-j];
            arr[N-1-i][N-1-j] = arr[N-1-j][i];
            arr[N-1-j][i] = tmp;
        }
    }    
}

// Alternative Way for Rotation through Clockwise 90degrees
void rotate(int arr[N][N])
{
    // Step1
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < i; j++)
        {
            int tmp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = tmp;
        }
    }

    // Step2
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N/2; j++)
        {
            int tmp = arr[i][j];
            arr[i][j] = arr[i][N-1-j];
            arr[i][N-1-j] = tmp;
        }
    }
}
void printArr(int arr[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}


int main()
{
    const int randMax = 32;
    int arr[N][N];
    srand(time(0));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            arr[i][j] = rand() % randMax;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------------------" << endl;
    //rotateClockwise90(arr);
    //rotateAntiClockwise90(arr);
    rotate(arr);
    printArr(arr);
}