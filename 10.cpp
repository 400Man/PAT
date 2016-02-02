// 23分 2*1 未过

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
  char map[37] = "0123456789abcdefghijklmnopqrstuvwxyz";
  char c[11],d[11];
  int tag,radix;
  scanf("%s %s %d %d",c,d,&tag,&radix);
    
  long long a = 0;
  char b[11];
  if(tag == 1)
  {
    for(int i = 0; i < strlen(c); i++)
    {
      if(isdigit(c[i]))
        a = a*radix + c[i]-'0';
      else
        a = a*radix + c[i]-'a'+10;
    }
    strcpy(b,d);
  }
  else
  {
    for(int i = 0; i < strlen(d); i++)
    {
      if(isdigit(d[i]))
        a = a*radix + d[i]-'0';
      else
        a = a*radix + d[i]-'a'+10;
    }
    strcpy(b,c);
  }
  // printf("%lld\n",a);
  if(strcmp(c,d)==0)
  {
    if(a <= 10)
    printf("%c\n",c[0]+1);
    else
    printf("%d\n",radix);
    return 0;
  }
  
  char max = 0;
  int maxNum;
  for(int i = 0; i < strlen(b) ; i++)
    if(b[i] > max)
      max = b[i];
  for(int i = 0; i < strlen(map);i++)
    if(max == map[i])
    {
      maxNum = i;
      break;
    }
  
  int i,u;
  long long num;
  int min,low,high;
  for(i = maxNum + 1 ; i < a;i++)   //改为二分搜索，而且有好多小错误，范围还没有搞清楚
  {
    num = 0;
    for(int j = 0; j < strlen(b); j++)
    { 
      for(int k = 0; k < strlen(map);k++)
        if(b[j] == map[k])
        {
          u = k;
          break;
        }
      num = num*i + u;
    }
    // printf("%lld ",num);
    if(num == a)
      {
        printf("%d\n",i>1?i:2);
        return 0;
      }
  }
  printf("Impossible\n");
  return 0;
}