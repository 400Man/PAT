#include <stdio.h>

int main()
{
  long long a,b,sign = 0;
  char s[20];
  int i = 0,j = 0;
  scanf("%lld %lld",&a,&b);
  a = a + b;
  if(a < 0)
  {
    sign = 1;
    a = -a;
  }
   
  if(a == 0)
    putchar('0');
  else
  {
  while(a != 0)
  {
    if((j%3 != 0)||(j==0))
    {
      s[i++] = a%10+'0';
      a /= 10;
    }
    else
    {
      s[i++] = ',';
      s[i++] = a%10+'0';
      a /= 10;
    }
    j++;
  }
  
  if(sign == 1)
    s[i++] = '-';
    
  for(int k = i;k >= 0; k--)
    putchar(s[k]);
  }
  putchar(10);
  return 0;
}