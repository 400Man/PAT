#include<stdio.h>
#include<string.h>

int num[10] = {0};

int dou(char a[],int size)
{
  int temp = 0;
  for(int i = size - 1; i >= 0 ; i--)
  {
    int u = (a[i] - '0')*2;
    a[i] = u%10 + temp + '0';
    if(u > 9)
      temp = 1;
    else
      temp = 0;
    // printf("%c",a[i]);
  }
  if(temp == 1)
    return 1;
  // putchar(10);
  return 0;
}


int ini(char a[], int size)
{
  for(int i = 0; i < size ; i++)
    num[a[i]-'0']--;
  for(int i = 0; i < 10;i++)
    if(num[i] != 0)
      return 0;
  return 1;
}

int main()
{
  char is[2][5] = {"No","Yes"};

  int size = 0;
  char a[30];
  scanf("%s",a);
  size = strlen(a);
  
  if(a[0] > '4')
  {
    printf("No\n1");
    dou(a,size);
    for(int i = 0 ; i < size ; i++)
      printf("%c",a[i]);
    putchar(10);
    return 0;
  }

  for(int i = 0; i < size ; i++)
    num[a[i]-'0']++;
  
  dou(a,size);

  printf("%s\n",is[ini(a,size)]);

  for(int i = 0 ; i < size ; i++)
    printf("%c",a[i]);
  putchar(10);
  return 0;
  
}