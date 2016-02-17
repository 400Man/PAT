#include<stdio.h>
#include<string.h>

bool isPa(char a[]){
  for(int i = 0, j = strlen(a)-1; i < j; i++,j--)
    if(a[i] != a[j])
      return false;
  return true;
}

void add(char a[],char u[]){
  int shift = 0;
  int i,j;
  for(i = 0,j = strlen(a)-1; i < strlen(a);i++,j--){
    if((a[i] + a[j] - '0' - '0' + shift) > 9){
      u[i] = a[i] + a[j] + shift - '0' - 10;
      shift = 1;
    }
    else{
      u[i] = a[i] + a[j] + shift - '0';
      shift = 0;
    }
  }
  if(shift == 1)
    u[i++] = '1';
  u[i] = '\0';
}

int main()
{
  char a[200];
  char u[200];
  int size;
  int times;
  int shift = 0;
  scanf("%s %d",a,&times);
  if(isPa(a)){
    printf("%s\n0\n",a);
    return 0;
  }

  for(int i = 0; i < times ; i++)
  {
    add(a,u);
    if(isPa(u)){
      printf("%s\n%d\n",u,i+1);
      return 0;
    }
    strcpy(a,u);
  }
  for(int i = strlen(a)-1;i>=0;i--)
    putchar(a[i]);
  printf("\n%d\n",times);
  return 0;
}