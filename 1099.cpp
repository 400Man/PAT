#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

int n;
int l[100],r[100],weight[100];
int size = 0;

struct node{
  int data;
  int lchild;
  int rchild;
}G[100];

void inOrder(int p){
  if(p == -1){
    return;
  }
  inOrder(G[p].lchild);
  G[p].data = weight[size++];
  inOrder(G[p].rchild);
}

int u=0;
queue<int> que;
void BFS(int p){
  que.push(p);
  while(!que.empty()){
    int a = que.front();
    que.pop();
    printf((u++)==n-1?"%d\n":"%d ",G[a].data);
    if(G[a].lchild != -1){
      que.push(G[a].lchild);
    }
    if(G[a].rchild != -1){
      que.push(G[a].rchild);
    }
  }
}

int main()
{
  scanf("%d",&n);
  for(int i = 0;i < n ; i++){
    scanf("%d %d",&l[i],&r[i]);
    G[i].lchild=l[i];
    G[i].rchild=r[i];
  }
  for(int i = 0;i < n; i++){
    scanf("%d",&weight[i]);
  }
  sort(weight,weight+n);
  inOrder(0);
  BFS(0);
  return 0;
}