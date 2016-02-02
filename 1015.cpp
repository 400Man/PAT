// 有一个两分的点怎么都不过

#include<stdio.h>

bool mark[100001];

int main()
{
  for(int i = 1; i < 100001; i++)
    mark[i] = false;
  for(int i = 2; i < 100001; i++)
  {
    if(mark[i] == true)
      continue;
    if(i<1001)
    for(int j = i*i ; j < 100001;j += i)
      mark[j] = true;
  }
  
  int a,b;
  int reverse[10];
  int size = 0;
  int num;
  do
  {
    scanf("%d",&a);
    if(a<0)
      break;
    scanf("%d",&b);
    num = 0;
    size = 0;
    if(mark[a] == true)
      printf("No\n");
    else
    {
      while(a!=0)
      {
        reverse[size++] = a%b;
        a /= b;
      }
      for(int i = 0; i < size ; i++)
      {
        num = num * b + reverse[i];
      }
      if(mark[num] == true)
        printf("No\n");
      else{
        if(num == 1)
          printf("No\n");
        else
          printf("Yes\n");
      }
    }
  }while(a >= 0);
  return 0;
}

