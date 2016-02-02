#include<stdio.h>
#include<string.h>

int main()
{
  char a[82];
  scanf("%s",a);
  int L = strlen(a);
  int n = L/3;
  int n1,n2,n3;
  if(L%3 != 0)
  n1 = n,n2 = L%3 + n, n3 = n;
  else
  n1 = n-1,n2 = L%3 + n+2, n3 = n-1;
  int u[n1+1][n2];
  for(int i = 0 ; i < n1+1;i++)
    for(int j = 0; j < n2; j++)
      u[i][j] = ' ';
  int i = 0, j = 0, k = 0;
  while(n1-->0)
  {
    u[i++][0] = a[j++];
  }
  while(n2-->0)
    u[i][k++] = a[j++];
  k--;
  while(n3-->0)
    u[--i][k]= a[j++];
  if(L%3 != 0)
  for(int i = 0 ; i < n + 1;i++)
  {
    for(int j = 0; j < L%3 + n; j++)
      printf("%c",u[i][j]);
    putchar('\n');
  }
  else
  for(int i = 0 ; i < n ;i++)
  {
    for(int j = 0; j < L%3 + n+2; j++)
      printf("%c",u[i][j]);
    putchar('\n');
  }
  return 0;
}