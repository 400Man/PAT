#include<cstdio>

int main()
{
  int n;
  scanf("%d",&n);
  int up = 0,down = 0;
  int a[n];
  for(int i = 0; i < n; i++)
    scanf("%d",&a[i]);
  for(int i = 1; i < n; i++)
  {
    int move = a[i] - a[i-1];
    (move>0)?(up += move):(down -= move);
  }
  printf("%d\n",(up+a[0])*6+down*4+n*5);
  return 0;
}