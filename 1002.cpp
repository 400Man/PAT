#include<stdio.h>

int main()
{
  double hash[1001] = {0.0};
  int N1,N2;
  int a;
  double f;
  
  scanf("%d",&N1);
  for(int i = 0; i< N1;i++)
  {
    scanf("%d %lf",&a,&f);
    hash[a] += f;
  }
  
  scanf("%d",&N2);
  for(int i = 0; i < N2; i++)
  {
    scanf("%d %lf",&a,&f);
    hash[a] += f;
  }
  
  int count = 0;
  for(int i = 0; i<= 1000; i++)
  {
    if(hash[i]!=0)
      count++;
  }
  
  printf("%d",count);
  for(int i = 1000; i >= 0; i--)
    if(hash[i] != 0)
      printf(" %d %.1f",i,hash[i]);
  putchar(10);
  return 0;
}