#include<stdio.h>
#include<algorithm>

using namespace std;

int ch(char a[]){
  int num = 0;
  for(int i = 0; i < 4; i++){
    num = num * 10 +a[i] - '0';
  }
  return num;
}

void itoa(char a[],int n){
  for(int i = 3;i >=0;i--){
    a[i] = n%10 + '0';
    n /= 10;
  }
  a[4] = '\0';
}

bool same(char a[]){
  for(int i = 1; i< 4; i++){
    if(a[i] != a[0])
      return false;
  }
  return true;
}

bool cmp(int a,int b){
  return a > b;
}

int main()
{
  char a[5];
  int b,first,second,third=0;
  scanf("%d",&b);
  itoa(a,b);
  if(same(a)){
    printf("%s - %s = 0000\n",a,a);
    return 0;
  }
  while(third != 6174){
      if(same(a)){
    printf("%s - %s = 0000\n",a,a);
    return 0;
  }
    sort(a,a+4,cmp);
    first = ch(a);
    for(int i = 0; i < 4; i ++){
      printf("%c",a[i]);
    }
    printf(" - ");
    sort(a,a+4);
    second = ch(a);
    for(int i = 0; i < 4; i++){
      printf("%c",a[i]);
    }
    printf(" = ");
    third = first - second;
    itoa(a,third);
    printf("%s\n",a);
  }
  return 0;
}