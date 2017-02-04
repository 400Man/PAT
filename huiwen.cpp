
#include<iostream>
using namespace std;

int main()
{
	string str;
	cin >> str;
	for(int i=0,j=str.length()-1;i<j;i++,j--)
		if(str[i]!=str[j]){
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	return 0;
}