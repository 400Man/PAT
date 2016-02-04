#include<stdio.h>

int main()
{
  int flag[10001]={0};
  int n;
  scanf("%d",&n);
  int a[n];
  for(int i = 0; i < n; i++){
    scanf("%d",&a[i]);
    flag[a[i]]++;
  }
  for(int i = 0; i < n;i++)
    if(flag[a[i]]==1){
      printf("%d\n",a[i]);
      goto end;
    }
  printf("None\n");
  end:
  return 0;
}