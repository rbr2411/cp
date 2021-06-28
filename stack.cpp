// Use an array to implement 3 Stacks
// Approach 1: Fixed Division
#include <bits/stdc++.h>
using namespace std;

#define stackSize 100
int buffer[stackSize * 3];
int stackPointer[] = {-1, -1, -1};


void push(int stackNum, int value) 
{
    if(stackPointer[stackNum] + 1 >= stackSize)
    { 
       cout << "Out of space" << endl;
       return;
    }
    stackPointer[stackNum]++;
    buffer[absTopOfStack(stackNum)] = value;
}

int pop(int stackNum)
{
    if(stackPointer[stackNum] == -1)
    {
        cout << "Trying to pop an empty stack." << endl;
        return INT32_MIN;
    }

    int value = buffer[absTopOfStack(stackNum)];
    buffer[absTopOfStack(stackNum)] = 0; // clear index
    stackPointer[stackNum]--; // decrement pointer
    return value;
}

int peek(int stackNum)
{
    int index = absTopOfStack(stackNum);
    return buffer[index];
}

bool isEmpty(int stackNum)
{
    return stackPointer[stackNum] == -1;
}

int absTopOfStack(int stackNum)
{
    return stackNum * stackSize + stackPointer[stackNum]; 
}

int main()
{



}