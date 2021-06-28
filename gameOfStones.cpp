#include <bits/stdc++.h>
int tab = -1;
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gameOfStones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER n as parameter.
 */

string gameOfStones(int n) {
    string s;
    if(n < 2)
        s = "Second";
    else if(n >= 2 && n <= 6)
        s = "First";
    else 
    {
        tab *= -1;
        s = gameOfStones(n-5);
        if(tab == 1)
        {
            if(s == "First")
                s = "Second";
            else s = "First";
        }
    }
    return s;    
}

int main()
{

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string result = gameOfStones(n);

        cout << result << "\n";
    }

    //fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
