//  10^10, 100次，long long 根本放不下

#include<stdio.h>

long long reverse(long long a){
  long long num=0;
  while(a!=0){
    num = num*10 + a%10;
    a /= 10;
  }
  return num;
}

bool isPa(long long b){
  char a[15];
  int size =0;
  for(int i = 0; b != 0; i++){
    a[size++] = b%10;
    b /= 10;
  }
  for(int i = 0, j = size-1; i<j;i++,j--){
    if(a[i] != a[j])
      return false;
  }
  return true;
}


int main()
{
  long long a;
  int b;
  scanf("%lld %d",&a,&b);
  long long u=a;
  if(isPa(u))
    {
      printf("%lld\n0\n",u);
      return 0;
    }
  for(int i = 0; i < b; i++)
  {
    u = a + reverse(a);
    if(isPa(u))
    {
      printf("%lld\n%d\n",u,i+1);
      return 0;
    }
    a = u;
  }
  printf("%lld\n%d\n",u,b);
  return 0;
}