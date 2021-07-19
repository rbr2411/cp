#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// sort pair in decreasing order of second int, then in decreasing order of first int
// if equal, sort in increasing order of first int
bool compare(vector<int> a, vector<int> b)
{
	if(a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]))
		return true;
	else return false;
}
int main()
{
	// vector<vector<int> > v;
	// v.push_back({1,4});
	// v.push_back({2,3});
	// v.push_back({4,6});
	// v.push_back({8,9});
	// v.push_back({2,4});
	// sort(v.begin(),v.end(),compare);

	// for(auto i : v)
	// {
	// 	cout << i[0] << " " << i[1] << endl;
	// }

	int candies[10];
	for(int i= 0; i < 10; i++)
	{
		candies[i] = 1;
	}
	for(int i = 1; i < 10; i++)
	{
		cout << i << " " << candies[i-1] << endl;
	}

	cout << endl;

	vector<int> v(10, 1);
	for(int i = 0;i < 10; i++)
	{
		cout << v[i] << endl;
	}
	return 0;
}


// Moore Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)
int moore(vector<int> &v)
{
	int majorityInd= 0;
	int count = 1;
	for(int i = 1; i < v.size(); i++)
	{
		v[majorityInd] == v[i]? count++ : count--;
		if(count == 0)
		{
			majorityInd = i;
			count = 1;
		}
	}
	return v[majorityInd];
}
