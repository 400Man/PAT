#include<stdio.h>

int main()
{
  char map[14] = "0123456789ABC";
  int n[3];
  int m[3][2];
  for(int i = 0; i < 3; i++)
    scanf("%d",&n[i]);
  printf("#");
  for(int i = 0; i < 3 ; i++)
    printf("%c%c",map[n[i]/13],map[n[i]%13]);
  putchar('\n');
  return 0;
}