#include<stdio.h>

int main()
{
  int hash[257] = {0};
  char a[10001];
  char c;
  int size=0;
  while((c=getchar())!='\n'){
    a[size++] = c;
  }
  while((c=getchar())!='\n'){
    hash[c] = 1;
  }
  for(int i = 0; i < size;i++)
    if(!hash[a[i]])
      printf("%c",a[i]);
  putchar(10);
  return 0;
}