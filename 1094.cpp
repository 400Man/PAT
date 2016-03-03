#include<stdio.h>
#include<vector>
#define max(a,b) a>b?a:b

using namespace std;

vector<int> Node[100];
int d[100] = {0};
int max_depth = 0;

void DFS(int index,int depth){
  max_depth = max(max_depth,depth);
  d[depth]++;
    for(int i = 0;i < Node[index].size(); i++){
      DFS(Node[index][i],depth+1);
  }
}

int main(){
  int n,m,mac=0;
  int u;
  scanf("%d %d",&n,&m);
  for(int i = 0;i < m; i++){
    int num,v;
    scanf("%d %d",&num,&v);
    for(int j = 0;j < v; j++){
      int c;
      scanf("%d",&c);
      Node[num].push_back(c);
    }
  }
  DFS(1,0);
  for(int i = 0;i < max_depth+1; i++){
    if(d[i] > mac){
      mac = d[i];
      u = i;
    }
  }
  printf("%d %d\n",mac,u+1);
}