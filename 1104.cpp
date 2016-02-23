#include<stdio.h>

int main()
{
  int n;
  scanf("%d",&n);
  double a[n];
  for(int i = 0;i < n; i++){
    scanf("%lf",&a[i]);
  }
  double sum = 0.0;
  for(int i = 1,j = n; i<= n;i++,j--){
    sum += (double)i*(double)j*a[i-1];
  }
  printf("%.2lf\n",sum);
}