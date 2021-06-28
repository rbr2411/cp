#include <bits/stdc++.h>
using namespace std;
// void reverse(char* str)
// {
// 	char* end = str;
// 	if(str)
// 	{
// 		while(*end)
// 		{
// 			end++;
// 		}
// 		//end--;// last character is '\0'
// 		while(str < end)
// 		{
// 			char tmp = *str;
// 			*str = *end;
// 			*end = tmp;
// 			str++;
// 			end--;
// 		}
// 	}
// }
int main() {
	char* str = "bon abba sai\0";	
	// reverse(str);
	string str = st;
	cout << st.length() << endl;
	sort(str.begin(), str.end());
	cout << str << endl;
	int n = str.length();
	bool flag = false;
	for(int i = 0; i < n-1; i++)
	{
		if(str[i] == str[i+1])
		{	
			cout << "Not Unique";
			flag = true;
			break;
		}
	}
	if(flag == false)	
		cout << "Contains Unique Characters" ;
}
