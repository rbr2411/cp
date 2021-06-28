#include <bits/stdc++.h>
using namespace std;

struct MyStack
{
    stack<int> s;
    int maxEle;

    void push(int x)
    {
        if(s.empty())
        {
            s.push(x);
            maxEle = x; 
            cout << "Element Inserted is: " << x << endl;
            return;
        }

        if(x > maxEle)
        {
            s.push(2 * x - maxEle);
            maxEle = x;

        }
        else
            s.push(x);

        cout << "Element Inserted is: " << x << endl;
    }

    void peek()
    {
        if(s.empty())
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        int t = s.top();
        
        (t > maxEle)? cout << "Peek Element is:" << maxEle << endl: cout <<"Peek Element is: " << t << endl;
    }

    void pop()
    {
        if(s.empty())
        {
            cout << "Stack is Empty" << endl;
            maxEle = INT32_MIN;
            return;
        }

        int t = s.top();
        s.pop();

        if(t > maxEle)
        {
            cout << "Element popped out: " << maxEle << endl;
            maxEle = 2 * maxEle - t; 
        }
        else
        {
            cout << "Element popped out: "<< t << endl;
        }
    }

    void getMax()
    {
        if(s.empty())
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        cout << "Max Element is: " << maxEle << endl;
    }
};

int main()
{
    MyStack s;
    s.push(2);
    s.push(12);
    s.getMax();
    s.push(7);
    s.push(5);
    s.peek();
    s.getMax();
    s.push(18);
    s.peek();
    s.getMax();
    s.pop();
    s.getMax();
    s.pop();
    s.peek();
    s.pop();
    s.getMax();
    s.peek();
    s.pop();
    s.pop();
    s.pop();
}