
#include<iostream>
using namespace std;

int main(){
	char str[90];
	int len=0;
	while(str[len++]=getchar())

	int flag[80],count=0;
	int i = 0;

	while(i<str.length()){
		if(str[i]==' '){
			flag[count++]=i;
			putchar(i);
		}
		i++;
		printf("haha\n");
	}

	flag[count]=str.length();

	for(i=count-1;i>0;i--){
		for(int j=flag[i];j<flag[i+1];j++){
			putchar(str[j]);
		}
		putchar(' ');
	}

	for(int j=0;j<flag[0];j++){
		putchar(str[j]);
	}
	putchar('\n');
}