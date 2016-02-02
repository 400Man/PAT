#include<stdio.h>

int palindromic(int a[],int size)
{
  for(int i = 0, j = size -1; i < j; i++,j--)
    if(a[i] != a[j])
      return 0;
  return 1;
}

int main()
{
  int n,b;
  int pali[100];
  int size = 0;
  char is[2][5] = {"No","Yes"};
  
  scanf("%d %d",&n,&b);
  
  do{
    pali[size++] = n%b;
    n /= b;
  }while(n != 0);
  
  printf("%s\n",is[palindromic(pali,size)]);
  
  for(int i = size -1; i >= 0;i--)
    printf((i==0)?"%d\n":"%d ",pali[i]);
  return 0;
}