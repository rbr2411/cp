#include <bits/stdc++.h>
using namespace std;

int hashFunc(string s, int base, int tableSize)
{
    int n = s.length();
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += s[i];
        sum = sum % base;
    }
    return sum % tableSize;
}

int collision_cnt(string s[], int base, int tableSize)
{
    int cnt = 0;
    int i = 0;
    set<int> values;
    while(s[i] != "")
    {
        int hashValue = hashFunc(s[i], base, tableSize);
        if(find(values.begin(),values.end(),hashValue) != values.end())
            cnt++;
        
        else
        {
            values.insert(hashValue);
        }
        i++;
    }

    return cnt;
}

vector<string> parser(FILE *fp)
{
    vector<string> s;
    while(!feof(fp))
    {   
        bool flag = false;
        string str = "";
        fscanf(fp,"%s ",str);
        for(char c: str)
        {
            if(!isalpha(c))
            {
                flag = true;
                break;
            }
        }
        if(flag == false)
        {
            s.push_back(str);
        }
    }
    return s;
}

int main()
{
    FILE* fp = fopen("aliceinwonderland.txt","r");
    vector<string> st = parser(fp);
    for(auto str: st)
    {
        cout << str << endl;
    }
    fclose(fp);
}