#include <bits/stdc++.h>
using namespace std;
#define capacity 5

class setOfStacks
{
    public: int total_size = 0;
    stack<int> * p[100];
    int i = 0;
    public: void push(int x)
    {
        if(total_size == 0)
        {
            stack<int> *s = new stack<int>();
            p[i] = s;
            s->push(x);
        }
        else if(p[i]->size() == capacity)
        {
            stack<int> *s = new stack<int>();
            p[++i] = s;
            s->push(x);
        }
        else p[i]->push(x);
        total_size++;
        cout << "Element pushed is: " << x << endl;
    }

    public: void pop()
    {
        if(total_size > 0)
        {
            cout << "Element popped out: "<< p[i]->top() << endl;
            p[i]->pop();
            if(p[i]->size() == 0)
                i--;
            total_size--;
        }
        else cout << "Trying to pop element from an empty stack" << endl;
    }

    public: void popAt(int index)
    {
        //index must vary from 0 to i for deletion
        if(index > i)
        {
            cout << "At index: " << index << " Out of bounds deletion." << endl;
            return;
        }
        if(p[index]->size() > 0)
        {
            int t = p[index]->top();
            p[index]->pop();
            cout << "Element popped out: " << t <<" at index " << index << endl;
            total_size--;
        }
        return;
    }
};


int main()
{
    setOfStacks st;
    srand(time(0));
    int modUlo = 32;
    for(int i = 0; i < 20; i++)
    {
        int a = rand() % modUlo;
        st.push(a);
    }
    cout << st.total_size << endl;
    st.popAt(4);
    st.popAt(3);
    st.popAt(2);
    st.popAt(1);
    st.popAt(0);
    cout << st.total_size << endl;
    for(int i = 0; i < 10; i++)
    {
        st.pop();
    }
    st.popAt(0);
    cout << st.total_size << endl;
}