#include<stdio.h>
#include<string.h>

int main()
{
  char num[10][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
  char a[101];
  int b[100];
  int size=0;
  scanf("%s",a);
  int sum = 0;
  for(int i = 0; i < strlen(a);i++)
    sum += a[i]-'0';
  if(sum == 0)
    printf("zero\n");
  while(sum>0)
  {
    b[size++] = sum%10;
    sum /= 10;
  }
  for(int i = size-1;i>=0;i--)
    printf(i==0?"%s\n":"%s ",num[b[i]]);
  return 0;
}
