#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
 
using namespace std;
 
int main()
{
	int n;
	cin >> n;
	vector<int> A(n+5, 0);
	long long S = 0;
	for (int i = 0; i < n; i++) cin >> A[i], S += A[i];
	if (S & 1) {
		cout << "NO";
		return 0;
	}
	unordered_map<long long, int> first, second;
 
	first[A[0]] = 1;
 
	for (int i = 1; i < n; i++) second[A[i]]++;
 
	long long sdash = 0;
 
	for (int i = 0; i < n ; i++) {
		sdash += A[i]; //first i numbers
		if (sdash == S / 2) {
			cout << "YES\n";
			return 0;
		}
		if (sdash < S / 2) {
			long long x = S / 2 - sdash;
			//delete element from second half, and insert into first half
			if (second[x] > 0) {
				cout << "YES\n";
				return 0;
			}
		}
		else {
			long long y = sdash - S / 2;
			if (first[y] > 0) {
				cout << "YES\n";
				return 0;
			}
		}
		//i+1
		first[A[i+1]]++;
		second[A[i + 1]]--;
	}
 
	cout << "NO\n";
 
 
}