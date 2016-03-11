#include<stdio.h>
#include<math.h>

int isPrime(int x){
  for(int i = 2;i < sqrt(x)+1;i++){
    if(x%i == 0){
      return 0;
    }
  }
  return 1;
}

int main()
{
  int n,Tsize;
  scanf("%d %d",&Tsize,&n);
  while(!isPrime(Tsize)){
    Tsize++;
  }
  int a[Tsize];
  int flag[100000] = {0};
  for(int i = 0;i < n; i++){
    for(int j = 0; j < Tsize; j++){
      if(flag[(i+j*j)%Tsize] == 0){
      a[(i+j*j)%Tsize] = i;
      flag[(i+j*j)%Tsize] = 1;
      printf("%d ",(i+j*j)%Tsize);
      break;
      }
    }
    printf("- ");
  }
  
  
  
  
  
  // printf("%d\n",Tsize);
}