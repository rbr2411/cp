//1.4
#include <bits/stdc++.h>
using namespace std;
std::string& ltrim(std::string &s)
{
    auto it = std::find_if(s.begin(), s.end(),
                    [](char c) {
                        return !std::isspace<char>(c, std::locale::classic());
                    });
    s.erase(s.begin(), it);
    return s;
}
 
std::string& rtrim(std::string &s)
{
    auto it = std::find_if(s.rbegin(), s.rend(),
                    [](char c) {
                        return !std::isspace<char>(c, std::locale::classic());
                    });
    s.erase(it.base(), s.end());
    return s;
}
 
std::string& trim(std::string &s) {
    return ltrim(rtrim(s));
}
string replace(string &s)
{
    int i = 0;
    while(i < s.length())
    {
        if(s[i] == ' ')
        {
            s.erase(s.begin() + i);
            s.insert(i, "%20");
            i += 3;
        }
        else i++;
    }
    return s;
}
int main()
{
    string s = "  Mr John Smith  ";
    trim(s);
    cout << replace(s) << endl;
}