// N disks Tower of Hanoi Problem can be solved in  
// min pow(2, N) -1 steps.

// Goal: Tower 3 must contain all the rings.
// for N: even -> start with second tower. 
// for N: odd -> start with third tower.

// should print all steps like move 1 -> tower 3.

#include <bits/stdc++.h>
using namespace std;
#define N 3

struct towerOfHanoi
{
    int moves = 0;
    stack<int> tower1, tower2, tower3;
    
    towerOfHanoi()
    {
        for(int i = 0; i < N; i++)
        {
            // here we are using rings 1,2,3,....N
            tower1.push(N-i);
        }
    }

    
    void moveDisks()
    {
        if(N <= 0)
            return;
        
    }
};

int main()
{
    towerOfHanoi th;
}