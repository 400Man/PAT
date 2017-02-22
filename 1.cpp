
#include<stdio.h>
#include<string>

struct time{
	int hour;
	int min;
	int sec;
}t[4];


int main(){
	int a,b,c,d;
	std::string str;
	scanf("%s %d:%d %d:%d",str.c_str(),&t[2].hour,&t[2].min,&t[3].hour,&t[3].min);
	scanf("%s %d:%d %d:%d",str.c_str(),&t[0].hour,&t[0].min,&t[1].hour,&t[1].min);
	printf("%s %d:%d %d:%d",str.c_str(),t[0].hour,t[0].min,t[1].hour,t[1].min);
}