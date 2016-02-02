#include<stdio.h>

int main()
{
  long long p=0,pa=0,pat=0;
  int c;
  while((c = getchar())!='\n'){
    if(c == 'P')
      p++;
    if(c == 'A')
      pa += p;
    if(c == 'T')
      pat += pa;
  }
  printf("%lld\n",pat%1000000007);
  return 0;
}