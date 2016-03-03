#include<stdio.h>
#include<vector>
#include<cmath>

using namespace std;

vector<int> G[100010];
int dep[100010] = {0};

void DFS(int root,int depth){
  if(G[root].size() == 0){
    dep[depth]++;
  }
  else{
    for(int i = 0;i < G[root].size(); i++){
      DFS(G[root][i],depth+1);
    }
  }
}

int main()
{
  int n;
  double price,r;
  scanf("%d %lf %lf",&n,&price,&r);
  for(int i = 0;i < n ; i++){
    int v;
    scanf("%d",&v);
    if(v != 0)
    for(int j = 0;j < v; j++){
      int u;
      scanf("%d",&u);
      G[i].push_back(u);
    }
  }
  DFS(0,0);
  int i=0;
  while(dep[i++]==0);
  printf("%.4lf %d\n",price*pow(1+r/100,i-1),dep[i-1]);
  
}
