#include <bits/stdc++.h>
using namespace std;

int main()
{
    // set<int> s; // Ordered set
    // s.insert(5);
    // s.insert(3);
    // s.insert(4);
    // s.insert(2);
    // s.insert(1);
    // s.insert(100);
    // s.erase(100);
    // for(auto it: s)
    //     cout << it << " ";
    // cout << endl;

    // unordered_set<int> res;
    // res.insert(5);
    // res.insert(3);
    // res.insert(4);
    // res.insert(2);
    // res.insert(1);
    // res.insert(10);
    // for(auto it: res)
    //     cout << it << " ";
    // cout << endl;

    // vector<int> v = {2, 3, 11, 14};
    // v.push_back(100);
    // bool present = binary_search(v.begin(), v.end(), 3);
    // cout << present << endl;

    // v.push_back(100);
    // v.push_back(100);
    // v.push_back(100);
    // v.push_back(100);

    // auto it = lower_bound(v.begin(), v.end(), 90);
    // cout << *(it) << endl;

    // v.push_back(123);
    // auto it2 = upper_bound(v.begin(), v.end(), 123);
    // cout << *it2 << endl;
    // for(auto it : v)
    //     cout << it << " ";
    // cout << endl;

    // map<int, int> mp;

    // mp[1] = 12;
    // mp[2] = 13;
    // mp[3] = 15;
    // map<char, int> freq;
    // string s = "I will make it. Things will improve.";
    // cout << s.length() << endl;
    // for(char c: s)
    // {
    //     freq[c]++;
    // }

    // for(auto it = freq.begin(); it != freq.end(); it++)
    //     cout << (*it).first << " " << (*it).second << endl;

    // set is ordered in ascending order
    // set<pair<int, int>> S;
    // S.insert({2,3});
    // S.insert({30,400});
    // S.insert({10,20});
    // S.insert({401, 450});

    // // find 31
    // pair<int,int> p = {31, INT16_MAX};
    // auto it = upper_bound(S.begin(), S.end(), p);
    // it--;
    // if(p.first >= (*(it)).first && p.first <= (*(it)).second)
    //     cout << (*(it)).first << " " << (*it).second;

    vector<int> v = {12, 31, 23, 78, 91};
    make_heap(v.begin(), v.end(), greater<int>()); // creates a max_heap by default

    cout << "Min elt: " << v.front() << endl;
    v.push_back(108);

    push_heap(v.begin(), v.end(), greater<int>()); // using push_heap to reorder the elts

    cout << v.front() << endl;
    for(int x: v)
        cout << x << " ";
    cout << endl;
    // push_back() -> push_heap()
    // pop_heap() -> pop_back()

    pop_heap(v.begin(), v.end());
    v.pop_back();
    cout << "Max elt after popping: " << v.front() << endl;

    // sorting heap using sort_heap()
    sort_heap(v.begin(), v.end());
    cout << "Heap elts after sorting are: ";
    for(int x: v)
        cout << x << " ";
    cout << "\n";

}