#include <bits/stdc++.h>
using namespace std;
string compress(string &s)
{
    string st = "";
    int count = 1;
    for(int i = 0; i < s.length() - 1; i++)
    {
        if(s[i] == s[i+1])
            count++;
        else
        {
            // Strings are mutable in C++
            // So, while concatenating a string to another, new copy is not created.
            // Instead the original string gets modified. 
            st += s[i];
            st += to_string(count);
            count = 1;
        }
    }
    st += s[s.length()-1]; 
    st += to_string(count);
    return (st.length() >= s.length())? s :st;
}
int main()
{
    string s = "aaaabcccccaaa";
    string s1 = "qwertyuiop";
    cout << compress(s) << endl;
    cout << compress(s1) << endl;
}   