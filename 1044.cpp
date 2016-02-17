// 暴力解，2个点不过

#include<stdio.h>
int main()
{
  int n,m;
  scanf("%d %d",&n,&m);
  int a[n],b[n],c[n];
  for(int i = 0; i < n ; i++)
    scanf("%d",&a[i]);
  int min = 999999999;
  int num,j;
  for(int i = 0; i < n ; i++){
    num = 0;
    for(j = i; num < m && j < n; j++){
      num += a[j];
    }
    c[i] = num;
    if(num < min && num >= m){
      min = num;
    }
    if(num >= m){
      b[i] = j;
    }
  }
  for(int i = 0; i < n;i++){
    if(c[i] == min)
      printf("%d-%d\n",i+1,b[i]);
  }
}