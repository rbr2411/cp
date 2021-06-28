#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    srand(time(0));

    int mod = 23;
    for(int i = 0; i < 10; i++)
    {
        q.push(rand() % mod);
    }

    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << "---------------" << endl;
    for(int i = 0; i < 10; i++)
    {
        int t = q.front();
        cout << t << endl;
        q.pop();
    }
    

    
}