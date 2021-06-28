#include <bits/stdc++.h>
using namespace std;

class myQueue
{
    stack<int> *first,*last = new stack<int>() ;
    int total_size = 0;

    public: void push(int x)
    {
        if(total_size == 0)
        {
            first = new stack<int>();
            first ->push(x);
            cout << "Element pushed in: " << x << endl;
            total_size++;
            return;
        }

        first->push(x);
        cout << "Element pushed in: " << x << endl;
        total_size++;
    }

    public: void pop()
    {
        if(total_size == 0)
        {
            cout << "Trying to pop from an empty queue" << endl;
            return;
        }

        if(last->size() == 0)
        {
            while(first->size())
            {
                int t = first->top();
                first->pop();
                last->push(t);
            }
        }

        int t = last->top();
        last->pop();
        total_size--;
        cout << "Element popped out: " << t << endl;
    }

    public: void getSize()
    {
        cout << total_size << endl;
    }
};

int main()
{
    srand(time(0));
    int mod = 29;
    myQueue mq;
    for(int i = 0; i < 15; i++)
    {
        int a = rand() % mod;
        mq.push(a);
    }

    mq.getSize();

    for(int i = 0; i < 10; i++)
    {
        mq.pop();
    }

    mq.getSize();

}
