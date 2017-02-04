
#include<iostream>

using namespace std;

int main(){
	int a,b,c;
	int ans[30],count=0;
	cin >> a >> b >> c;
	int sum=a+b;
	do{
		ans[count++]=sum%c;
		sum/=c;
	}while(sum!=0);
	for(int i=count-1;i>=0;i--)
		printf("%d",ans[i]);
	putchar(10);
}