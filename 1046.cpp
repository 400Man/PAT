#include<stdio.h>

#include<algorithm>
using namespace std;
int que[100005]={0};
int main()
{
  int M,N;
  scanf("%d",&N);
  
  for(int i = 1; i <= N ;i++){
    scanf("%d",&que[i]);
    sum += que[i];
    que[i] = sum;
  }

  scanf("%d",&M);
  for(int i = 0; i < M;i++){
    int u,v;
    int ans = 0;
    scanf("%d %d",&u,&v);
    if(u > v)
      swap(u,v);
    ans = que[v-1] - que[u-1];
    printf("%d\n",min(ans,sum-ans));
  }
  
  return 0;
}