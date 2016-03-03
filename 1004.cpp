#include<stdio.h>
#include<queue>
#include<vector>
#define N 110

using namespace std;

vector<int> G[N];
int leaf[N] = {0};
int max_h = 1;

void dfs(int index, int h){
  max_h = max(h,max_h);       //妙法：递归时候求高度
  if(G[index].size() == 0){
    leaf[h]++;
    return;
  }
  for(int i = 0;i < G[index].size(); i++){
    dfs(G[index][i],h+1);
  }
}

int main()
{
  int n,m;
  scanf("%d %d",&n,&m);
  for(int i = 0;i < m ; i++){
    int u,v;
    scanf("%d %d",&u,&v);
    for(int j = 0;j < v;j++){
      int k;
      scanf("%d",&k);
      G[u].push_back(k);
    }
  }
  dfs(1,1);
  printf("%d",leaf[1]);
  for(int i = 2; i <= max_h; i++){
    printf(" %d",leaf[i]);
  }
  putchar(10);
  return 0;
}