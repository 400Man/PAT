#include<stdio.h>
#include<math.h>

int isPrime(int x){
  if(x <= 1)
    return 0;
  for(int i = 2;i <= (int)sqrt(1.0*x);i++)
    if(x%i == 0)
      return 0;
  return 1;
}

int main()
{
  int n,Tsize,j,key;
  int flag[100000] = {0};
  scanf("%d %d",&Tsize,&n);
  while(!isPrime(Tsize)){
    Tsize++;
  }
  
  for(int i = 0;i < n; i++){
    scanf("%d",&key);
    for(j = 0; j < Tsize; j++){
      int m = (key + j*j)%Tsize;
      if(flag[m] == 0){
      flag[m] = 1;
      printf(i == n-1?"%d\n":"%d ",m);
      break;
      }
    }
    if(j >= Tsize)
      printf(i == n-1?"-\n":"- ");
  }
  return 0;
}