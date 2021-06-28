#include <bits/stdc++.h>
using namespace std;

class Animal
{
    // Cat - 'C', Dog - 'D'
    queue<pair<char, int>> q;
    public: void enqueue(char c, int x)
    {
        q.push(make_pair(c,x));
        cout << "Animal added: " << c << " " << x << endl;
    }

    public: void dequeueAny()
    {
        if(q.empty())
        {
            cout << "No animal is available to adopt." << endl;
            return;
        }
        pair<char, int> p;
        p = q.front();
        q.pop();
        cout << "Animal adopted: " << p.first << " " << p.second << endl;
    }

    public: void dequeueDog()
    {
        if(q.empty())
        {
            cout << "No animal is available to adopt." << endl;
            return;
        }
        bool flag = false;
        queue<pair<char,int>> r;
        while(!q.empty())
        {
            pair<char,int> p = q.front();
            q.pop();
            if(p.first == 'D' && !flag)
            {
                cout << "Animal adopted: " << p.first << " " << p.second << endl;
                flag = true;
                continue;
            }
            r.push(p);
        }
        q = r;
    }

    public: void dequeueCat()
    {
        if(q.empty())
        {
            cout << "No animal is available to adopt." << endl;
            return;
        }
        bool flag = false;
        queue<pair<char,int>> r;
        while(!q.empty())
        {
            pair<char,int> p = q.front();
            q.pop();
            if(p.first == 'C' && !flag)
            {
                cout << "Animal adopted: " << p.first << " " << p.second << endl;
                flag = true;
                continue;
            }
            r.push(p);
        }
        q = r;
    }

};

int main()
{
    srand(time(0));
    int mod1 = 2, mod2 = 67;
    Animal an;
    for(int i = 0; i < 20; i++)
    {
        char j = rand() % mod1 + 'C';
        int k = rand() % mod2;
        an.enqueue(j,k);
    }  
    cout << "-------------------" << endl;
    for(int i = 0; i < 5; i++)
    {
        an.dequeueAny();
    }
    cout << "-------------------" << endl;
    an.dequeueCat();
    an.dequeueDog();
    an.dequeueDog();
    an.dequeueCat();
    an.dequeueDog();
    an.dequeueDog();
    an.dequeueCat();
    an.dequeueDog();
    an.dequeueCat();
    an.dequeueDog();
    an.dequeueDog();
    an.dequeueDog();
    an.dequeueCat();
}