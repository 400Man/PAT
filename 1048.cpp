#include<stdio.h>
#include<string.h>

int a[100001];

int main()
{
  int n,m;
  scanf("%d %d",&n,&m);
  int u;
  memset(a,0,sizeof(a));
  for(int i = 0; i < n; i++){
    scanf("%d",&u);
    a[u] += 1;
  }
  for(int i = 0 ; i < 100001 && i < m; i++){
    if(a[i] != 0){
      a[i]--;
      if(a[m-i] != 0){
        printf("%d %d\n",i,m-i);
        return 0;
      }
    }
  }
  printf("No Solution\n");
  return 0;
}