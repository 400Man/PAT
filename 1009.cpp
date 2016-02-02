#include<stdio.h>
#include<math.h>

int main()
{
  float e[2001] = {0.0};
  int k1,k2;
  
  scanf("%d",&k1);
  int a[k1];
  float c[k1];
  for(int i = 0; i < k1 ; i++)
    scanf("%d %f",&a[i],&c[i]);
  
  scanf("%d",&k2);
  int b[k2];
  float d[k2];
  for(int i = 0; i < k2 ; i++)
    scanf("%d %f",&b[i],&d[i]);
    
  for(int i = 0; i < k1; i++)
    for(int j = 0; j < k2; j++)
      e[a[i]+b[j]] += c[i]*d[j];
  int count = 0;
  for(int i = 0; i < 2001; i++)
    if(e[i] != 0)
      count++;
  printf("%d",count);
  for(int i = 2000; i >= 0; i--)
    if(e[i] != 0)
      printf(" %d %.1f",i,e[i]);
  putchar(10);
  return 0;
}