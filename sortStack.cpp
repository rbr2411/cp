#include <bits/stdc++.h>
using namespace std;

stack<int> sort(stack<int> s)
{
    stack<int> r;
    while (!s.empty())
    {
        int tmp = s.top();
        s.pop();
        while(!r.empty() && r.top() > tmp)
        {
            int t = r.top();
            r.pop();
            s.push(t);
        }
        r.push(tmp);
    }
    return r;
}

int main()
{
    srand(time(0));
    int mod = 61;
    stack<int> org;
    
    for(int i = 0; i < 10; i++)
    {
        int a = rand() % mod;
        cout << a << " ";
        org.push(a);
    }
    cout << endl;
    
    stack<int> s = sort(org);
    while(s.size())
    {
        int t = s.top();
        s.pop();
        cout << t << " ";
    }
    cout << endl;
}